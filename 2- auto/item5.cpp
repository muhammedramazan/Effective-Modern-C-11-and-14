// -- -- Prefer auto to explicit type declarations -- --

#include <iostream>
// #include <unordered_map>

template <typename It>
void dwim(It b, It e) {
  while (b != e) {
    typename std::iterator_traits<It>::value_type currValue = *b;
  }
}

template <typename It>
void dwim_1(It b, It e) {
  while (b != e) {
    auto currValue = *b;
  }
}

int main(int argc, char const *argv[]) {
  /* code */

  int x1;  // potentially uninitialized
  // auto x2;      // error! initializer required
  auto x3 = 0;  // fine, x's value is well-defined
  return 0;
}
