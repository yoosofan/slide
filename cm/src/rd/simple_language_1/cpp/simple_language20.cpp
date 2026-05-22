#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cmath>

using namespace std;

enum TokenType {
  IDENTIFIER, INT_NUMBER, WHILE_KEYWORD, PLUS_OPERATOR,
  MINUS_OPERATOR, MUL_OPERATOR, DIV_OPERATOR, LPAR_OPERATOR,
  RPAR_OPERATOR, END_INPUT_FILE, UNKNOWN_TOKEN, LET_INSTRUCTION,
  PRINT_INSTRUCTION, BEGIN_KEYWORD, END_KEYWORD, EOL_DELIMETER,
  ASSIGN_OPERATOR
};

struct Token {
  TokenType type;
  int n;
  string s;
} t;

// --- GLOBAL STATE ---
string buffer;
size_t tindex = 0;
bool run_mode = true;

// Stack frame to save execution environment for loops
struct LoopFrame {
  size_t loop_start_index;
  bool parent_run_mode;
};
vector<LoopFrame> loopStack;

// --- SYMBOL TABLE ---
class SymbolTable {
  unordered_map<string, int> memory;
  unordered_map<string, TokenType> keywords;
public:
  SymbolTable() {
    keywords["BEGIN"] = BEGIN_KEYWORD;
    keywords["END"]   = END_KEYWORD;
    keywords["WHILE"] = WHILE_KEYWORD;
    keywords["LET"]   = LET_INSTRUCTION;
    keywords["PRINT"] = PRINT_INSTRUCTION;
  }

  TokenType lookup(const string& s) {
    if (keywords.contains(s)) return keywords[s];
    return IDENTIFIER;
  }

  void assign(const string& name, int val) { memory[name] = val; }
  int readVal(const string& name) { return memory.contains(name) ? memory[name] : 0; }
} symTable;

// --- PROTOTYPES ---
void B(); void L(); void do_assign(); void do_while(); void do_print();
int E(); int T(); int F();
void error(const string& msg);

// --- LEXER ---
Token getToken() {
  while (tindex < buffer.size() && (buffer[tindex] == ' ' || buffer[tindex] == '\t')) {
    tindex++;
  }

  if (tindex >= buffer.size() || buffer[tindex] == '\0') {
    t = {END_INPUT_FILE, 0, ""};
    return t;
  }

  char current = buffer[tindex];
  switch (current) {
    case '(': t = {LPAR_OPERATOR, 0, "("}; tindex++; break;
    case ')': t = {RPAR_OPERATOR, 0, ")"}; tindex++; break;
    case '+': t = {PLUS_OPERATOR, 0, "+"}; tindex++; break;
    case '-': t = {MINUS_OPERATOR, 0, "-"}; tindex++; break;
    case '*': t = {MUL_OPERATOR, 0, "*"};  tindex++; break;
    case '/': t = {DIV_OPERATOR, 0, "/"};  tindex++; break;
    case '=': t = {ASSIGN_OPERATOR, 0, "="}; tindex++; break;
    case '\n':
      t = {EOL_DELIMETER, 0, "\n"};
      tindex++;
      while (tindex < buffer.size() && isspace(buffer[tindex])) {
        tindex++;
      }
      break;
    default:
      if (isdigit(current)) {
        t.type = INT_NUMBER;
        t.n = 0;
        while (tindex < buffer.size() && isdigit(buffer[tindex])) {
          t.n = t.n * 10 + (buffer[tindex] - '0');
          tindex++;
        }
        t.s = to_string(t.n);
      }
      // Fixed character verification issue by using standard system macro wrapper
      else if (isalpha(current) || current == '_') {
        t.s = "";
        while (tindex < buffer.size() && (isalnum(buffer[tindex]) || buffer[tindex] == '_')) {
          t.s += buffer[tindex];
          tindex++;
        }
        t.type = symTable.lookup(t.s);
      } else {
        error(string("Illegal character: ") + current);
      }
      break;
  }
  return t;
}

// --- PARSER / EXECUTION CORE ---
void A() {
  t = getToken();
  B();
  if (t.type != END_INPUT_FILE) error("Unrecognized trailing token after root block");
  cout << "Accept" << endl;
}

void B() {
  if (t.type != BEGIN_KEYWORD) error("Block must start with BEGIN");
  t = getToken();
  if (t.type != EOL_DELIMETER) error("Missing newline after BEGIN");
  t = getToken();

  while (t.type == LET_INSTRUCTION || t.type == PRINT_INSTRUCTION || t.type == WHILE_KEYWORD) {
    L();
    if (t.type != EOL_DELIMETER) error("Statements must terminate with a newline");
    t = getToken();
  }

  if (t.type != END_KEYWORD) error("Block must close with END");
  t = getToken();
  if (t.type != EOL_DELIMETER) error("Missing newline after END");
}

void L() {
  switch (t.type) {
    case LET_INSTRUCTION:   do_assign(); break;
    case PRINT_INSTRUCTION: do_print();  break;
    case WHILE_KEYWORD:     do_while();  break;
    default: break;
  }
}

void do_assign() {
  t = getToken();
  if (t.type != IDENTIFIER) error("Assignment missing target variable identifier");
  Token var = t;
  t = getToken();
  if (t.type != ASSIGN_OPERATOR) error("Let statement missing operational assignment '='");
  t = getToken();
  int val = E();
  if (run_mode) symTable.assign(var.s, val);
}

void do_print() {
  t = getToken();
  int val = E();
  if (run_mode) cout << val << endl;
}

void do_while() {
  // Push current scope state to runtime execution stack to safely track nested positions
  loopStack.push_back({ tindex, run_mode });

  t = getToken();
  while (true) {
    // Read the condition expression under parent state
    int cond = E();
    if (!loopStack.back().parent_run_mode) cond = 0;

    if (cond == 0) run_mode = false;

    if (t.type != EOL_DELIMETER) error("Missing newline after while evaluation condition");
    t = getToken();

    // Parse / interpret inner loop block
    B();

    if (cond == 0) {
      // Restore outer loop execution state and peel frame off the stack
      run_mode = loopStack.back().parent_run_mode;
      loopStack.pop_back();
      break;
    } else {
      // Reset loop tracker back to the start position saved in the stack frame
      tindex = loopStack.back().loop_start_index;
      t = getToken();
    }
  }
}

// --- EXPRESSIONS ---
int E() {
  int val = T();
  while (t.type == PLUS_OPERATOR || t.type == MINUS_OPERATOR) {
    TokenType op = t.type;
    t = getToken();
    int rhs = T();
    if (op == PLUS_OPERATOR) val += rhs;
    else val -= rhs;
  }
  return val;
}

int T() {
  int val = F();
  while (t.type == MUL_OPERATOR || t.type == DIV_OPERATOR) {
    TokenType op = t.type;
    t = getToken();
    int rhs = F();
    if (op == MUL_OPERATOR) val *= rhs;
    else {
      if (rhs == 0) error("Division by zero");
      val /= rhs;
    }
  }
  return val;
}

int F() {
  int val = 0;
  if (t.type == LPAR_OPERATOR) {
    t = getToken();
    val = E();
    if (t.type != RPAR_OPERATOR) error("Missing matching execution closing parenthesis ')'");
  } else if (t.type == INT_NUMBER) {
    val = t.n;
  } else if (t.type == IDENTIFIER) {
    val = symTable.readVal(t.s);
  } else {
    error("Unexpected expression token parsed in factor F");
  }
  t = getToken();
  return val;
}

void error(const string& msg) {
  cerr << "Syntax/Runtime Error: " << msg << " at buffer position " << tindex << endl;
  exit(1);
}

int main() {
  buffer =
    "BEGIN\n"
    "LET X = 5\n"
    "PRINT X\n"
    "WHILE X\n"
    "BEGIN\n"
    "PRINT X\n"
    "LET X = X - 1\n"
    "END\n"
    "PRINT 999\n"
    "END\n";

  A();
  return 0;
}


/*
 * Thanks to Gemini AI for helping making this code
 *
Here is my old C++ code implementing it. Please check it if there is any incosistency in it with the grammar and the result.
for the record, the program is not exactly similar to the grammar but do almost the same.

cm/src/rd/simple_language_1/cpp/simple_language_1.cpp
*/
