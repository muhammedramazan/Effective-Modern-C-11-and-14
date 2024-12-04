// -- -- Know how to view deduced types -- --
#include <iostream>
#include <boost/type_index.hpp>
template<typename T>
void f_boost(const T& param)
{
using std::cout;
using boost::typeindex::type_id_with_cvr;
// show T
cout << "T ="<< type_id_with_cvr<T>().pretty_name()<< '\n';
// show param's type
cout << "param = "<< type_id_with_cvr<decltype(param)>().pretty_name()<< '\n';
}
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

  f_boost(&w);
  f_boost(theAnswer);

  return 0;
}
