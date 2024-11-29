// -- Understand decltype -- //

#include <iostream>
#include <vector>

class Widget {};

const int i = 0;  // decltype(i) is const int
decltype(i) i_{2};
bool f(Widget&);  // decltype(w) is const Widget&
decltype(f) f_;

template <typename T>
T t_f(T);
decltype(t_f<int>) d_t_f;
// decltype(t_f) d_t_f_e;

// ---- ---- ---- ---- ---- ---- ---- ----
// trailing return type syntax c++11
template <typename Container, typename Index>
auto authAndAccess_trailing_return(Container& c, Index i) -> decltype(c[i]) {
  std::cout << "authAndAccess_trailing_return" << std::endl;
  return c[i];
}

// ---- ---- ---- ---- ---- ---- ---- ----
// c++14
template <typename Container, typename Index>
auto authAndAccess_auto(Container& c, Index i) {
  std::cout << "authAndAccess_auto" << std::endl;
  return c[i];
}

// ---- ---- ---- ---- ---- ---- ---- ----
template <typename Container, typename Index>
decltype(auto) authAndAccess_decltype_auto(Container& c, Index i) {
  std::cout << "authAndAccess_decltype_auto" << std::endl;

  return c[i];
}
// ---- ---- ---- ---- ---- ---- ---- ----
template <typename Container, typename Index>
decltype(auto) authAndAccess_decltype_auto_forward(Container&& c, Index i) {
  std::cout << "authAndAccess_decltype_auto_forward" << std::endl;

  return std::forward<Container>(c)[i];
}
// ---- ---- ---- ---- ---- ---- ---- ----
template <typename Container, typename Index>
auto authAndAccess_trailing_return_forward(Container&& c, Index i)
    -> decltype(std::forward<Container>(c)[i]) {
  std::cout << "authAndAccess_trailing_return_forward" << std::endl;

  return std::forward<Container>(c)[i];
}

int main(int argc, char const* argv[]) {
  /* code */

  std::vector<int> v_1{1};
  std::vector<int> v_2(1100);
  std::cout << "v_1[12] : " << v_1[12] << std::endl;
  std::cout << "v_2[12] : " << v_2[12] << std::endl;
  decltype(v_1) ttt_1;
  decltype(v_1[1]) ttt_2{v_1[1]};
  decltype(v_2) ttt_3;
  decltype(v_2[1]) ttt_4{v_2[1]};
  std::vector<bool> v_3(1100);
  decltype(v_3) ttt_5;
  decltype(v_3[1]) ttt_6;
  // ---- ---- ---- ---- ---- ---- ---- ----

  std::vector<int> int_e;
  std::vector<bool> bool_e;

  authAndAccess_trailing_return(int_e, 1);
  authAndAccess_trailing_return(bool_e, 1);
  // Run time error
  authAndAccess_auto(int_e, 1);
  authAndAccess_auto(bool_e, 1);
  authAndAccess_decltype_auto(int_e, 1);
  authAndAccess_decltype_auto(bool_e, 1);
  Widget ww; 
  const Widget& cww =ww ;
  auto myWidget1w = cww;
  decltype(auto) myWidget2w = cww;
  decltype(cww) myWidget3w = cww;

  // Eerror
  //authAndAccess_decltype_auto(std::move(int_e));
  return 0;
}
