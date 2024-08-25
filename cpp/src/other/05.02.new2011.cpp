
//	Declares a named variable as a reference, that is, an alias to an already-existing object or function.
//	Syntax

//	A reference variable declaration is any simple declaration whose declarator has the form
//	& attr(optional) declarator 	(1)
//	&& attr(optional) declarator 	(2) 	(since C++11)
//	1) Lvalue reference declarator: the declaration S& D; declares D as an lvalue reference to the type determined by decl-specifier-seq S.
//	2) Rvalue reference declarator: the declaration S&& D; declares D as an rvalue reference to the type determined by decl-specifier-seq S.
//	declarator 	- 	any declarator except another reference declarator (there are no references to references)
//	attr(C++11) 	- 	optional list of attributes

//	A reference is required to be initialized to refer to a valid object or function: see reference initialization.

//	There are no references to void and no references to references.

//	Reference types cannot be cv-qualified at the top level; there is no syntax for that in declaration, and if a qualification is introduced through a typedef, decltype, or template type argument, it is ignored.

//	References are not objects; they do not necessarily occupy storage, although the compiler may allocate storage if it is necessary to implement the desired semantics (e.g. a non-static data member of reference type usually increases the size of the class by the amount necessary to store a memory address).

//	Because references are not objects, there are no arrays of references, no pointers to references, and no references to references:

int& a[3]; // error
int&* p;   // error
int& &r;   // error

//	Reference collapsing

//	It is permitted to form references to references through type manipulations in templates or typedefs, in which case the reference collapsing rules apply: rvalue reference to rvalue reference collapses to rvalue reference, all other combinations form lvalue reference:

typedef int&  lref;
typedef int&& rref;
int n;
lref&  r1 = n; // type of r1 is int&
lref&& r2 = n; // type of r2 is int&
rref&  r3 = n; // type of r3 is int&
rref&& r4 = 1; // type of r4 is int&&

//	(This, along with special rules for template argument deduction when T&& is used in a function template, forms the rules that make std::forward possible.)
//	(since C++11)
//	Lvalue references

//	Lvalue references can be used to alias an existing object (optionally with different cv-qualification):
//	Run this code

#include <iostream>
#include <string>

int main() {
    std::string s = "Ex";
    std::string& r1 = s;
    const std::string& r2 = s;

    r1 += "ample";           // modifies s
//  r2 += "!";               // error: cannot modify through reference to const
    std::cout << r2 << '\n'; // prints s, which now holds "Example"
}

//	They can also be used to implement pass-by-reference semantics in function calls:
//	Run this code

#include <iostream>
#include <string>

void double_string(std::string& s) {
    s += s; // 's' is the same object as main()'s 'str'
}

int main() {
    std::string str = "Test";
    double_string(str);
    std::cout << str << '\n';
}

//	When a function's return type is lvalue reference, the function call expression becomes an lvalue expression:
//	Run this code

#include <iostream>
#include <string>

char& char_number(std::string& s, std::size_t n) {
    return s.at(n); // string::at() returns a reference to char
}

int main() {
    std::string str = "Test";
    char_number(str, 1) = 'a'; // the function call is lvalue, can be assigned to
    std::cout << str << '\n';
}


//	Rvalue references

//	Rvalue references can be used to extend the lifetimes of temporary objects (note, lvalue references to const can extend the lifetimes of temporary objects too, but they are not modifiable through them):
//	Run this code

#include <iostream>
#include <string>

int main() {
    std::string s1 = "Test";
//  std::string&& r1 = s1;           // error: can't bind to lvalue

    const std::string& r2 = s1 + s1; // okay: lvalue reference to const extends lifetime
//  r2 += "Test";                    // error: can't modify through reference to const

    std::string&& r3 = s1 + s1;      // okay: rvalue reference extends lifetime
    r3 += "Test";                    // okay: can modify through reference to non-const
    std::cout << r3 << '\n';
}


//	More importantly, when a function has both rvalue reference and lvalue reference overloads, the rvalue reference overload binds to rvalues (including both prvalues and xvalues), while the lvalue reference overload binds to lvalues:
//	Run this code

#include <iostream>
#include <utility>

void f(int& x) {
    std::cout << "lvalue reference overload f(" << x << ")\n";
}

void f(const int& x) {
    std::cout << "lvalue reference to const overload f(" << x << ")\n";
}

void f(int&& x) {
    std::cout << "rvalue reference overload f(" << x << ")\n";
}

int main() {
    int i = 1;
    const int ci = 2;
    f(i);  // calls f(int&)
    f(ci); // calls f(const int&)
    f(3);  // calls f(int&&)
           // would call f(const int&) if f(int&&) overload wasn't provided
    f(std::move(i)); // calls f(int&&)

    // rvalue reference variables are lvalues when used in expressions
    int&& x = 1;
    f(x);            // calls f(int& x)
    f(std::move(x)); // calls f(int&& x)
}


//	This allows move constructors, move assignment operators, and other move-aware functions (e.g. std::vector::push_back()) to be automatically selected when suitable.

//	Because rvalue references can bind to xvalues, they can refer to non-temporary objects:

int i2 = 42;
int&& rri = std::move(i2); // binds directly to i2

//	This makes it possible to move out of an object in scope that is no longer needed:

std::vector<int> v{1,2,3,4,5};
std::vector<int> v2(std::move(v)); // binds an rvalue reference to v
assert(v.empty());

//	(since C++11)
//	Forwarding references

Forwarding references are a special kind of references that preserve the value category of a function argument, making it possible to forward it by means of std::forward. Forwarding references are either:
1) function parameter of a function template declared as rvalue reference to cv-unqualified type template parameter of that same function template:

template<class T>
int f(T&& x) {                    // x is a forwarding reference
    return g(std::forward<T>(x)); // and so can be forwarded
}

int main() {
    int i;
    f(i); // argument is lvalue, calls f<int&>(int&), std::forward<int&>(x) is lvalue
    f(0); // argument is rvalue, calls f<int>(int&&), std::forward<int>(x) is rvalue
}

template<class T>
int g(const T&& x); // x is not a forwarding reference: const T is not cv-unqualified

template<class T> struct A {
    template<class U>
    A(T&& x, U&& y, int* p); // x is not a forwarding reference: T is not a
                             // type template parameter of the constructor,
                             // but y is a forwarding reference
};

2) auto&& except when deduced from a brace-enclosed initializer list:

auto&& vec = foo();       // foo() may be lvalue or rvalue, vec is a forwarding reference
auto i = std::begin(vec); // works either way
(*i)++;                   // works either way
g(std::forward<decltype(vec)>(vec)); // forwards, preserving value category

for (auto&& x: f()) {
  // x is a forwarding reference; this is the safest way to use range for loops
}

auto&& z = {1, 2, 3}; // *not* a forwarding reference (special case for initializer lists)

See also template argument deduction and std::forward.
	(since C++11)
Dangling references

Although references, once initialized, always refer to valid objects or functions, it is possible to create a program where the lifetime of the referred-to object ends, but the reference remains accessible (dangling). Accessing such a reference is undefined behavior. A common example is a function returning a reference to an automatic variable:

std::string& f()
{
    std::string s = "Example";
    return s; // exits the scope of s:
              // its destructor is called and its storage deallocated
}

std::string& r = f(); // dangling reference
std::cout << r;       // undefined behavior: reads from a dangling reference
std::string s = f();  // undefined behavior: copy-initializes from a dangling reference

Note that rvalue references and lvalue references to const extend the lifetimes of temporary objects (see Reference initialization for rules and exceptions).

If the referred-to object was destroyed (e.g. by explicit destructor call), but the storage was not deallocated, a reference to the out-of-lifetime object may be used in limited ways, and may become valid if the object is recreated in the same storage (see Access outside of lifetime for details).
