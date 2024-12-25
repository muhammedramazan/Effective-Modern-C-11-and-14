// -- -- Prefer auto to explicit type declarations -- --

#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

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

class Widget {
 public:
  bool operator<(Widget&) const { return false; }
};

int main(int argc, char const* argv[]) {
  /* code */

  int x1;  // potentially uninitialized
  // auto x2;      // error! initializer required
  auto x3 = 0;  // fine, x's value is well-defined

  auto derefUPLess =                         // comparison func.
      [](const std::unique_ptr<Widget>& p1,  // for Widgets
         const std::unique_ptr<Widget>& p2)  // pointed to by
  { return *p1 < *p2; };                     // std::unique_ptrs

  auto derefLess =        // C++14 comparison
      [](const auto& p1,  // function for
         const auto& p2)  // values pointed
  { return *p1 < *p2; };  // to by anything
  std::unique_ptr<Widget> pp(new Widget);
  derefLess(pp, pp);
  // pointer-like
  //

  // bool(const std::unique_ptr<Widget>&, // C++11 signature for
  // const std::unique_ptr<Widget>&)      // std::unique_ptr<Widget>
  // comparison function
  std::function<bool(const std::unique_ptr<Widget>&,
                     const std::unique_ptr<Widget>&)>
      func;

  std::function<bool(const std::unique_ptr<Widget>&,
                     const std::unique_ptr<Widget>&)>
      derefUPLess = [](const std::unique_ptr<Widget>& p1,
                       const std::unique_ptr<Widget>& p2) { return *p1 < *p2; };

  std::vector<int> v;
  unsigned sz = v.size();
  auto a_sz = v.size();

  std::unordered_map<std::string, int> m;
  for (const std::pair<std::string, int>& p : m) {
    ;
    // do something with p
  }
  for (const auto& p : m) {
    ;
  }
  return 0;
}
