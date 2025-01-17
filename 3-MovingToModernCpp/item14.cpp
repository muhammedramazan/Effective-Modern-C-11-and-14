// Declare functions noexcept if they won’t emit exceptions.
#include <iostream>
#include <vector>
using namespace std;
class A {
 public:
  A() { cout << "A" << endl; }
  ~A() { cout << "~A" << endl; }
};
class B {
 public:
  B() { cout << "B" << endl; }
  ~B() { cout << "~B" << endl; }
};
class C {
 public:
  C() { cout << "C" << endl; }
  ~C() { cout << "~C" << endl; }
};
class D {
 public:
  D() { cout << "D" << endl; }
  ~D() { cout << "~D" << endl; }
};
D fff() {
  C c;
  // throw 12;
  return D{};
}
D ff() {
  B b;
  fff();
  return D{};
}

D f() {
  // int f() throw() {
  A a;
  ff();
  return D{};
}

class MyClass {
 public:
  MyClass() = default;

  // Move constructor
  MyClass(MyClass&&) noexcept { std::cout << "Move constructor  called\n"; }

  // Copy constructor
  MyClass(const MyClass&) noexcept { std::cout << "Copy constructor called\n"; }
};

int main(int argc, char const* argv[]) {
  /* code */
  try {
    f();
    /* code */
  } catch (...) {
    std::cerr << "catch" << '\n';
  }

  std::vector<MyClass> vec_my;
  MyClass cll;
  cout << "---" << endl;
  vec_my.push_back(MyClass{});
  vec_my.push_back(cll);

  return 0;
}