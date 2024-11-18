// Understand template type deduction.
struct ParamType {
} expr;

template <typename T>
void f(ParamType param) {};

template <typename T>
void f_1(const T& param) {};

int main(int argc, char const* argv[]) {
  {
    ;
    f<int>(expr);
  }
  {
    int x = 0;
    f_1(x);
    // T is `int` But type of param is `const int&`
    // call f with an int
  }
  return 0;
}
