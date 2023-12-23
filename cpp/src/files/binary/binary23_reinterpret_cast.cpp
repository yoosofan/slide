#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdint>
int main(){ // https://en.cppreference.com/w/cpp/io/basic_istream/read
  // read() is often used for binary I/O
  std::string bin = {'\x12', '\x12', '\x12', '\x12'};
  std::istringstream raw(bin);
  std::uint32_t n;
  if(raw.read(reinterpret_cast<char*>(&n), sizeof n))
    std::cout << std::hex << std::showbase << n << '\n';

  // prepare file for next snippet
  std::ofstream("test.txt", std::ios::binary) << "abcd1\nabcd2\nabcd3";

  // read entire file into string
  if(std::ifstream is{"test.txt", std::ios::binary | std::ios::ate}) {
    auto size = is.tellg();
    std::string str(size, '\0'); // construct string to stream size
    is.seekg(0);
    if(is.read(&str[0], size))
        std::cout << str << '\n';
  }
}
/* https://en.cppreference.com/w/cpp/io/basic_ostream/write
#include <iostream>
int main(){
  int n = 0x41424344;
  std::cout.write(reinterpret_cast<char*>(&n), sizeof n) << '\n';

  char c[]="This is sample text.";
  std::cout.write(c, 4).write("!\n", 2);
}
*/
/* https://en.cppreference.com/w/cpp/io/basic_ifstream
#include <iostream>
#include <fstream>
#include <string>
int main() {
  std::string filename = "Test.b";
  // prepare a file to read
  double d = 3.14;
  std::ofstream(filename, std::ios::binary).write(reinterpret_cast<char*>(&d), sizeof d)
     << 123 << "abc";
  // open file for reading
  std::ifstream istrm(filename, std::ios::binary);
  if (!istrm.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else {
    double d;
    istrm.read(reinterpret_cast<char*>(&d), sizeof d); // binary input
    int n;
    std::string s;
    if (istrm >> n >> s)                               // text input
      std::cout << "read back from file: " << d << ' ' << n << ' ' << s << '\n';
  }
}*/