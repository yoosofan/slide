#include <cctype> // g++ --std="c++23"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
enum Type {
  ID, NUM, WHILE, LET, PRINT, BEG, END, EOL,
  ADD, SUB, MUL, DIV, ASG, LPR, RPR, EOF_T
};
struct Tok{Type t; int v; string s;} tk;
string buf; size_t p = 0; bool run = true;
struct Frame { size_t idx; bool r; };
vector<Frame> stk;
class Sym { unordered_map<string, int> mem;
  unordered_map<string, Type> kw; public:
  Sym() {
    kw["BEGIN"] = BEG; kw["END"] = END;
    kw["WHILE"] = WHILE; kw["LET"] = LET;
    kw["PRINT"] = PRINT;
  }
  Type get(const string& s) {
    return kw.contains(s) ? kw[s] : ID;
  }
  void set(const string& n, int v){mem[n] = v;}
  int read(const string& n) {
    return mem.contains(n) ? mem[n] : 0;
  }
} sym; void err() { exit(1); }
void B(); void L(); int E(); int T(); int F();
Tok getTk(){
  while (p < buf.size() &&
    (buf[p] == ' ' || buf[p] == '\t')) p++;
  if (p >= buf.size() || buf[p] == '\0')
    return tk = {EOF_T, 0, ""};
  char c = buf[p];
  switch (c) {
    case '(': tk = {LPR, 0, "("}; p++; break;
    case ')': tk = {RPR, 0, ")"}; p++; break;
    case '+': tk = {ADD, 0, "+"}; p++; break;
    case '-': tk = {SUB, 0, "-"}; p++; break;
    case '*': tk = {MUL, 0, "*"}; p++; break;
    case '/': tk = {DIV, 0, "/"}; p++; break;
    case '=': tk = {ASG, 0, "="}; p++; break;
    case '\n':
      tk = {EOL, 0, "\n"}; p++;
      while (p < buf.size() && isspace(buf[p]))
        p++;
      break;
    default:
      if (isdigit(c)) {
        tk.t = NUM; tk.v = 0;
        while (p < buf.size() && isdigit(buf[p]))
          tk.v = tk.v * 10 + (buf[p++] - '0');
      } else if (isalpha(c) || c == '_') {
        tk.s = "";
        while (p < buf.size() &&
               (isalnum(buf[p]) || buf[p] == '_'))
          tk.s += buf[p++];
        tk.t = sym.get(tk.s);
      } else err();
  } return tk;
}
void expect(Type type) {
  if (tk.t != type) err();
  getTk();
} void B() {
  expect(BEG); expect(EOL);
  while (tk.t == LET || tk.t == PRINT ||
         tk.t == WHILE){ L(); expect(EOL);}
  expect(END); expect(EOL);
} void L() {
  if (tk.t == LET) {
    getTk(); string n = tk.s; expect(ID);
    expect(ASG); int v = E();
    if (run) sym.set(n, v);
  } else if (tk.t == PRINT) {
    getTk(); int v = E();
    if (run) cout << v << endl;
  } else if (tk.t == WHILE) {
    stk.push_back({p, run}); getTk();
    while (true) { int c = E();
      if (!stk.back().r) c = 0;
      if (c == 0) run = false;
      expect(EOL); B();
      if (c == 0) {
        run = stk.back().r; stk.pop_back();
        break;
      }else{p = stk.back().idx; getTk();}
    }
  }
} int E() { int v = T();
  while (tk.t == ADD || tk.t == SUB) {
    Type o = tk.t; getTk(); int r = T();
    v = (o == ADD) ? v + r : v - r;
  } return v;
} int T() { int v = F();
  while (tk.t == MUL || tk.t == DIV) {
    Type o = tk.t; getTk(); int r = F();
    if (o == MUL) v *= r;
    else { if (r == 0) err(); v /= r; }
  }  return v;
} int F() { int v = 0;
  if (tk.t == LPR) {
    getTk(); v = E(); expect(RPR);
  } else if (tk.t == NUM) {
    v = tk.v; getTk();
  } else if (tk.t == ID) {
    v = sym.read(tk.s); getTk();
  } else err();
  return v;
} int main() { buf =
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
  getTk(); B();
  if (tk.t != EOF_T) err();
  cout << "Accept" << endl;
}


/*
 * Thanks to Gemini AI for helping making this code
 *
 Thanks, please minimize it considering 52 characters limit per line. Also, use C++ best minimization standard for the code.
*/
