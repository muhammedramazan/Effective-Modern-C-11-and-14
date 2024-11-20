// -- Understand template type deduction. -- //

#include <iostream>

int d_f_1() { return 1; }
int d_f_2() {
  int a = 1;
  return a;
}
int& d_f_3() {
  int a = 1;
  return a;
}
int&& d_f_4() {
  int a = 1;
  return std::move(a);
}

struct ParamType {
} expr;

template <typename T>
void f(T param) {
  T& t = param;
}

// Case 1 : `ParamType is a Reference or Pointer, but not a Universal Reference`

// 1-1 Refrence type

// 1. If expr’s type is a reference, ignore the reference part.
// 2. Then pattern-match expr’s type against ParamType to determine T.

template <typename T>
void f_refrence_param_type(T& param) {
  T& t = param;
}
// param is a reference

// 1-2 Pointer type

template <typename T>
void f_pointer_param_type(T* param) {}  // param is now a pointer

// Case 2: `ParamType is a Universal Reference`

template <typename T>
void f_universal_refrence(T&& param) {}  // param is now a universal reference

// Case 3: ParamType is Neither a Pointer nor a Reference

template <typename T>
void f_none_pointer_or_refrence(T param) {}  // param is now passed by value

// --- --- --- --- --- --- --- --- --- --- --- ---
// Array argument

void f_arr_1(int a[12]) {
  // this range-based 'for' statement requires a suitable "begin" function and
  // none was found
  ;
  // for(auto &aa: a)
  //   aa =2;
}
void f_arr_2(int (&a)[12]) {
  for (auto& aa : a) aa = 2;
}
template <typename T>
void f_array_by_value(T param) {}
// template with by-value parameter
template <typename T>
void f_array_by_refrence(T& param) {}
// template with by-reference parameter

// Function Arguments

void someFunc(int, double){}
// someFunc is a function;
// type is void(int, double)
template <typename T>
void f1(T param){}  // in f1, param passed by value
template <typename T>
void f2(T& param){}  // in f2, param passed by ref
int main(int argc, char const* argv[]) {
  // Enter
  { f(expr); }
  // Case 1 ParamType is a Reference or Pointer, but not a Universal Reference
  // 1-1 refrence_param_type
  {
    int x = 1;
    const int cx = 12;
    int& rx = x;
    const int& crx = x;
    int* p = &x;
    const int* cp = p;
    int* const pc = p;
    const int* const cpc = p;

    f_refrence_param_type(x);
    f_refrence_param_type(cx);
    f_refrence_param_type(rx);
    f_refrence_param_type(crx);
    f_refrence_param_type(p);
    f_refrence_param_type(cp);
    f_refrence_param_type(pc);
    f_refrence_param_type(cpc);
  }
  // 1-2 pointer_param_type
  {
    // prerequisites
    std::cout << "-- -- -- -- \n const pointer" << std::endl;
    int x_1 = 1;
    const int c_x_1 = 1;
    int x_2 = 2;
    const int* constptr = &x_1;
    std::cout << " e:1 -> " << *constptr << std::endl;
    constptr = &x_2;
    std::cout << " e:2 -> " << *constptr << std::endl;
    x_2 = 3;
    std::cout << " e:3 -> " << *constptr << std::endl;
    // *constptr = 4;  Error : expression must be a modifiable lvalue
    x_1 = 5;
    int* const ptrconst = &x_1;
    std::cout << " e:5 -> " << *ptrconst << std::endl;
    x_1 = 6;
    std::cout << " e:6 -> " << *ptrconst << std::endl;
    *ptrconst = 7;
    std::cout << " e:7 -> " << x_1 << std::endl;
    // ptrconst = &x_2;  Error : expression must be a modifiable lvalue
    // const int* const constptrconst; Error : uninitialized ‘const
    // constptrconst’
    const int* const constptrconst = &x_1;

    int* p_1 = &x_1;
    // int* p_2 = &c_x_1;
    // int* p_3 = constptr;
    int* p_4 = ptrconst;
    // int* p_5 = constptrconst;

    const int* cp_1 = &x_1;
    const int* cp_2 = &c_x_1;
    const int* cp_3 = constptr;
    const int* cp_4 = ptrconst;
    const int* cp_5 = constptrconst;

    int* const pc_1 = &x_1;
    // int* const pc_2 = &c_x_1;
    // int* const pc_3 = constptr;
    int* const pc_4 = ptrconst;
    // int* const pc_5 = constptrconst;

    const int* const cpc_1 = &x_1;
    const int* const cpc_2 = &c_x_1;
    const int* const cpc_3 = constptr;
    const int* const cpc_4 = ptrconst;
    const int* const cpc_5 = constptrconst;

    int x = 27;                 // as before
    const int* px = &x;         // px is a ptr to x as a const int
    const int* const pxp = &x;  // pxp is a const ptr to x as a const int

    const int cx = 12;
    int& rx = x;
    const int& crx = x;
    int* p = &x;
    const int* cp = p;
    int* const pc = p;
    const int* const cpc = p;
    // f_pointer_param_type(x);
    // f_pointer_param_type(cx);
    // f_pointer_param_type(rx);
    // f_pointer_param_type(crx);
    f_pointer_param_type(p);
    f_pointer_param_type(cp);
    f_pointer_param_type(pc);
    f_pointer_param_type(cpc);
  }
  // Case 2 ParamType is a Universal Reference
  {
    int x = 1;
    const int cx = 12;
    int& rx = x;
    const int& crx = x;
    int* p = &x;
    const int* cp = p;
    int* const pc = p;
    const int* const cpc = p;
    f_universal_refrence(x);
    f_universal_refrence(cx);
    f_universal_refrence(rx);
    f_universal_refrence(crx);
    f_universal_refrence(p);
    f_universal_refrence(cp);
    f_universal_refrence(pc);
    f_universal_refrence(cpc);
    f_universal_refrence(1);

    (d_f_1());
    f_universal_refrence(d_f_2());
    f_universal_refrence(d_f_3());
    f_universal_refrence(d_f_4());
  }
  // Case 3 ParamType is Neither a Pointer nor a Reference
  {
    int x = 1;
    const int cx = 12;
    int& rx = x;
    const int& crx = x;
    int* p = &x;
    const int* cp = p;
    int* const pc = p;
    const int* const cpc = p;

    f_none_pointer_or_refrence(x);
    f_none_pointer_or_refrence(cx);
    f_none_pointer_or_refrence(rx);
    f_none_pointer_or_refrence(crx);
    f_none_pointer_or_refrence(p);
    f_none_pointer_or_refrence(cp);
    f_none_pointer_or_refrence(pc);
    f_none_pointer_or_refrence(cpc);
  }
  // Array Argument
  {
    int a[12];
    using arr_12 = int[12];
    f_arr_1(a);
    f_arr_2(a);
    f_array_by_value(a);
    f_array_by_refrence(a);
  }
  // Function Arguments
  {
    f1(someFunc);  // param deduced as ptr-to-func;
    // type is void (*)(int, double)
    f2(someFunc);  // param deduced as ref-to-func;
                   // type is void (&)(int, double)
  }
  std::cout <<"Done" << std::endl;
  return 0;
}
