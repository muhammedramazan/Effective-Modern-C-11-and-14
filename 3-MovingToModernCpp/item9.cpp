// Prefer alias declarations to typedefs.
#include <iostream>
#include <list>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::unique_ptr<std::unordered_map<std::string, std::string>>
    UPtrMapSS_TYP;

using UPtrMapSS_ALIAS =
    std::unique_ptr<std::unordered_map<std::string, std::string>>;

typedef void (*FP_TYP)(int, const string &);

using FP_ALIAS = void (*)(int, const string &);

void A(int, const string &) { cout << "void A(int , string&)" << endl; }

class Widget {};

template <typename T>
class MyAlloc {
 public:
  using value_type = T;

  constexpr void deallocate(T *__p, size_t __n) {}
};

template <typename T>
struct MyAllocList {
  typedef std::list<T, MyAlloc<T>> type;
};

MyAllocList<Widget>::type lw;

int main(int argc, char const *argv[]) {
  /* code */
  std::vector<int> a;
  FP_TYP aa = &A;
  FP_ALIAS bb = &A;
  int ii;
  string ss;
  aa(ii, ss);
  bb(ii, ss);

  // template<typename _Tp>
  // using remove_const_t = typename remove_const<_Tp>::type;
  remove_const_t<int> aaaa;
}
