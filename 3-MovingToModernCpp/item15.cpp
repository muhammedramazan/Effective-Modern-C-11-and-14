// Use constexpr whenever possible.

#include <iostream>

constexpr int f_const() { return 1; }
constexpr int f_const_v(int a) { return a; }

class temp {
 private:
  /* data */
 public:
  int a = 12, b = 13;
};

class Point {
 public:
  constexpr Point(double xVal = 0, double yVal = 0) noexcept
      : x(xVal), y(yVal) {}
  constexpr double xValue() const noexcept { return x; }
  constexpr double yValue() const noexcept { return y; }
  constexpr void setX(double newX) noexcept  // C++14
  {
    x = newX;
  }
  constexpr void setY(double newY) noexcept  // C++14
  {
    y = newY;
  }

 private:
  double x, y;
};

constexpr Point reflection(const Point& p) noexcept {
  Point result;              // create non-const Point
  result.setX(-p.xValue());  // set its x and y values
  result.setY(-p.yValue());
  return result;  // return copy of it
}

constexpr Point midpoint(const Point& p1, const Point& p2) noexcept {
  return {(p1.xValue() + p2.xValue()) / 2,   // call constexpr
          (p1.yValue() + p2.yValue()) / 2};  // member funcs
}
int main(int argc, char const* argv[]) {
  constexpr int v1 = f_const();
  constexpr double v2 = f_const();
  constexpr int v3 = f_const_v(12);
  constexpr temp v4{};
  constexpr int v5 = v4.a;
  constexpr int v6 = v4.b;
  std::cout << v1 << std::endl;
  std::cout << v4.a << " " << v4.b << std::endl;
  std::cout << v5 << std::endl;

  constexpr Point p1(9.4, 27.7);  // as above
  constexpr Point p2(28.8, 5.3);
  constexpr auto mid = midpoint(p1, p2);
  constexpr auto reflectedMid = reflection(mid);
  return 0;
}
