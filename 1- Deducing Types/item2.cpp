// -- Understand auto type deduction.-- //

#include <iostream>

int d_f_1() { return 1; }
int d_f_2() {
  int a = 1;
  return a;
}
int &d_f_3() {
  int a = 1;
  return a;
}
int &&d_f_4() {
  int a = 1;
  return std::move(a);
}

template <typename T>
void f_non(T param) {}
template <typename T>
void f_refrence(T &param) {}
template <typename T>
void f_universal_refrence(T &&param) {}

template <typename T>
void f_init_list(std::initializer_list<T> initList) {}

int main(int argc, char const *argv[]) {
  // Case 1
  // Case 1
  {
    int x = 1;
    const int cx = 12;
    int &rx = x;
    const int &crx = x;
    int *p = &x;
    const int *cp = p;
    int *const pc = p;
    const int *const cpc = p;
    auto &a1 = x;
    auto &a2 = cx;
    auto &a3 = rx;
    auto &a4 = crx;
    auto &a5 = p;
    auto &a6 = cp;
    auto &a7 = pc;
    auto &a8 = cpc;
    // auto &a8 = 1;
    // auto &a10 = d_f_1();
    // auto &a11 = d_f_2();
    auto &a12 = d_f_3();
    // auto &a13 = d_f_4();
  }
  // Case 2
  {
    int x = 1;
    const int cx = 12;
    int &rx = x;
    const int &crx = x;
    int *p = &x;
    const int *cp = p;
    int *const pc = p;
    const int *const cpc = p;
    auto &&a1 = x;
    auto &&a2 = cx;
    auto &&a3 = rx;
    auto &&a4 = crx;
    auto &&a5 = p;
    auto &&a6 = cp;
    auto &&a7 = pc;
    auto &&a8 = cpc;
    auto &&a9 = 12;
    auto &&a10 = d_f_1();
    auto &&a11 = d_f_2();
    auto &&a12 = d_f_3();
    auto &&a13 = d_f_4();
  }
  // Case 3
  {
    int x = 1;
    const int cx = 12;
    int &rx = x;
    const int &crx = x;
    int *p = &x;
    const int *cp = p;
    int *const pc = p;
    const int *const cpc = p;
    auto a1 = x;
    auto a2 = cx;
    auto a3 = rx;
    auto a4 = crx;
    auto a5 = p;
    auto a6 = cp;
    auto a7 = pc;
    auto a8 = cpc;
    auto a9 = 12;
    auto a10 = d_f_1();
    auto a11 = d_f_2();
    //auto a12 = d_f_3();
  }
  {
    {
      int x1 = 27;
      int x2(27);
      int x3 = {27};
      int x4{27};
    }
    {
      auto x1 = 27;
      auto x2(27);
      auto x3 = {27};
      auto x4{27};  // ?
    }
    {
      auto i = {1, 2, 3, 4};
      auto i_int = {1};
      // auto i_1{1, 2, 3, 4};
      // braced initialization of a variable declared with a placeholder type
      // but without `=` requires exactly one element inside the braces
      auto i_int_1{1};
      f_non(i);
      //f_non({i});
      // f_non({1,2,3,4});
      f_refrence(i);
      // f_refrence({1,2,3,4});
      f_universal_refrence(i);
      // f_universal_refrence({1,2,3,4});
      f_init_list(i);
      f_init_list({11, 23, 9});


      auto f_p = d_f_1;
      auto &f_r = *f_p;
      auto &f_r_1 = d_f_1;
    }
  }
  std::cout <<"Done" << std::endl;
  return 0;
}
