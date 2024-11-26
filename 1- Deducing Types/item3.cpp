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
  return 0;
}
