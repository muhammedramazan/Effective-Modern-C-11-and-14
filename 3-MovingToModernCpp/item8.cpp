// Prefer nullptr to 0 and NULL

#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

class Widget {
 public:
};

// void f(decltype(NULL)){cout << "f(int)" << endl;}
void f(int) { cout << "f(int)" << endl; }
void f(bool) { cout << "f(bool)" << endl; }
void f(void *) { cout << "f(void*)" << endl; }

int f1(std::shared_ptr<Widget> spw) {
  cout << "int f1" << endl;
  return int{};
}
double f2(std::unique_ptr<Widget> upw) {
  cout << "double f2" << endl;
  return double{};
}
bool f3(Widget *pw) {
  cout << "bool f3" << endl;
  return bool{};
}
using MuxGuard = std::lock_guard<std::mutex>;

template <typename FuncType, typename MuxType, typename PtrType>
auto lockAndCall(FuncType func, MuxType &mutex,
                 PtrType ptr) -> decltype(func(ptr)) {
  MuxGuard g(mutex);
  return func(ptr);
}
template <typename FuncType, typename MuxType, typename PtrType>
auto lockAndCall1(FuncType func, MuxType &mutex,
                  PtrType ptr) -> decltype(func(0)) {
  MuxGuard g(mutex);
  return func(0);
}
template <typename FuncType, typename MuxType, typename PtrType>
auto lockAndCall2(FuncType func, MuxType &mutex,
                  PtrType ptr) -> decltype(func(NULL)) {
  MuxGuard g(mutex);
  return func(NULL);
}
int main(int argc, char const *argv[]) {
  decltype(NULL) type_a;
  auto type_b = NULL;
  cout << typeid(NULL).name() << endl;  // NULL is long
  cout << typeid(long).name() << endl;

  f(0);
  // f(NULL); //more than one instance of overloaded function "f" matches the
  // argument list:C/C++(308) function "f(int)" (declared at line 8) function
  // "f(bool)" (declared at line 9) function "f(void *)" (declared at line 10)
  // argument types are: (long)

  decltype(nullptr) type_n_1;
  auto type_n_2 = nullptr;

  f(nullptr);

  if (0 == nullptr) cout << "0 == nullptr" << endl;
  if (0 == NULL) cout << "0 == NULL" << endl;
  if (NULL == nullptr) cout << "nullptr == NULL" << endl;

  cout << "-----------" << endl;
  std::mutex f1m, f2m, f3m;
  {
    {
      MuxGuard g(f1m);
      auto result = f1(0);  // lock mutex for f1
    }
    {
      MuxGuard g(f2m);
      auto result = f2(NULL);  // lock mutex for f2
    }
    {
      MuxGuard g(f3m);
      auto result = f3(nullptr);
    }
  }
  {
    // auto result1 = lockAndCall(f1, f1m, 0);
    auto result1 = lockAndCall1(f1, f1m, 0);
    // auto result2 = lockAndCall(f2, f2m, NULL);
    auto result2 = lockAndCall2(f2, f2m, NULL);
    auto result3 = lockAndCall(f3, f3m, nullptr);

    decltype(0) iii = 0;
    decltype(NULL) iiii = NULL;
    f1(0);
    // f1(iii);
    f1(NULL);
    // f1(iiii);
  }
  return 0;
}
