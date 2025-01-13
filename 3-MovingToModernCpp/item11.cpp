// Prefer deleted functions to private undefined ones.
#include <iostream>
using namespace std;

class A {
 public:
  A() = default;
  A(const A&) = delete;

 private:
  A& operator=(const A&) = delete;
};

void ff(int) { cout << "void ff(int) " << endl; }
void ff(char) = delete;
void ff(bool) = delete;
void ff(double) = delete;

int main(int argc, char const* argv[]) {
  int a;
  A a1;
  // A a2(a1);
  A a2;
  // a2 = a1;

  ff(12);

  return 0;
}
