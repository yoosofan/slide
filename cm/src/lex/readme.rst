sudo apt install g++
sudo apt install flex

flex programName.l
gcc lex.yy.c -lfl
./a.out <input.txt

Rules

1. Order of regular expression
2. Larger accepted input
3. More specific input
