// -- -- Understand decltype -- -- //
#include <vector>
// Part 1
const int i = 0;
decltype(i) i_dec{12};  //  is const int

class Widget {};

const Widget w__;
const Widget& cw__{w__};
bool f(const Widget& w) {
  decltype(w) w_dec{w};  // is const Widget&
  decltype(f) f_dec;     // is bool(const Widget&)
  return false;
}

struct Point {
  int x, y;
};
decltype(Point::y) point_y_dec;  // is int
decltype(Point::x) point_x_dec;  // is int

template <typename T>
class vector_temp {
 public:
  T& operator[](std::size_t index) { return arr[1]; }
  int arr[12];
};

vector_temp<int> v_temp;
decltype(v_temp) v_temp_dec;  // is vector_temp<int>

std::vector<int> v_int;
decltype(v_int[0]) v_int_dec{v_int[0]};  // int&
std::vector<bool> v_bool;
decltype(v_bool[0]) v_bool_dec;  // std::vector<bool>::reference

// -- -- -- --
// 1-)
template <typename Container, typename Index>
auto authAndAccess_auto(Container& c, Index i) -> auto {
  return c[i];
}
// 2-)
template <typename Container, typename Index>
auto authAndAccess_trailing(Container& c, Index i) -> decltype(c[i]) {
  return c[i];
}
// 3-)
template <typename Container, typename Index>
decltype(auto) authAndAccess_decltype_auto(Container& c, Index i) {
  return c[i];
}
decltype(auto) w_dec_auto_ = w__;
auto w_auto_ = (w__);
decltype(auto) c_w_dec_auto_ = cw__;
auto c_w_auto_ = (cw__);
// 4-)
template <typename Container, typename Index>
auto authAndAccess_forward_trailing(Container&& c, Index i)
    -> decltype(std::forward<Container>(c)[i]) {
  return std::forward<Container>(c)[i];
}
// 5-)
template <typename Container, typename Index>
decltype(auto) authAndAccess_forward_dec_auto(Container&& c, Index i) {
  return std::forward<Container>(c)[i];
}
// 6-)
int x__t = 0;
decltype((x__t)) x___x;
int main(int argc, char const* argv[]) {
  /* code */

  decltype(v_temp[0]) v_temp_0{v_temp[0]};  // decltype(v[0]) is int&
  if (v_temp[0] == 0) {
  }
  return 0;
}
