// Prefer scoped enums to unscoped enums.

#include <iostream>
#include <tuple>
#include <type_traits>
using namespace std;

enum Color { black, white, red };

// auto black = false; //‘auto black’ redeclared as different kind of entity

enum class Color_s { black_s, white_s, red_s };
auto black_s = false;

// Color_s c_1 = white_s;
Color_s c_2 = Color_s::white_s;
auto c_3 = Color_s::white_s;

template <typename E>
constexpr auto toUType(E enumerator) noexcept {
  return static_cast<std::underlying_type_t<E>>(enumerator);
}
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
