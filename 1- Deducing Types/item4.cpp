// -- -- Know how to view deduced types -- --
#include <iostream>

template <typename T>
class TD;


class Widget{
  public:
};
template <typename T>
void f(const T& param) {
  using std::cout;
  cout << "T = " << typeid(T).name() << '\n';
  cout << "param = " << typeid(param).name() << '\n';  // show
}
int main(int argc, char const* argv[]) {
  // IDE -> edit code phase

  const int theAnswer = 42;
  auto x = theAnswer;
  auto y = &theAnswer;

  // Compiler

  // TD<decltype(x)> xType; compiler error
  // TD<decltype(y)> yType; compiler error

  // Run Time
  std::cout << typeid(x).name() << '\n';
  std::cout << typeid(y).name() << '\n';
  const Widget w{};
  f(&w);
  f(theAnswer);

  return 0;
}
