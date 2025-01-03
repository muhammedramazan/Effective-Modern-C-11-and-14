// Distinguish between () and {} when creating objects.
#include <atomic>
#include <iostream>
#include <vector>
using namespace std;
class B {
 public:
  B() {}
  B(int) {}
  B(B &) {}
  B(B &&) {}
};
class A {
 public:
  static int counter;
  int id;
  ~A() { cout << "~A() " << id << endl; };
  A() {
    id = ++counter;
    cout << "A() " << id << endl;
  };

  // A(int) {
  //   id = ++counter;
  //   cout << "A(int) " << id << endl;
  // };
  A(float) {
    id = ++counter;
    cout << "A(float) " << id << endl;
  };
  A(double) {
    id = ++counter;
    cout << "A(double) " << id << endl;
  };

  A(int, int, int) {
    id = ++counter;
    cout << "A(int,int,int) " << id << endl;
  };
  A(const A &) {
    id = ++counter;
    cout << "A(&) " << id << endl;
  }
  A(const A &&) {
    id = ++counter;
    cout << "A(&&) " << id << endl;
  }

  A &operator=(A &) {
    cout << "A operator=(A&)" << id << endl;
    return *this;
  }
  A &operator=(A &&) {
    cout << "A operator=(A&&)" << id << endl;
    return *this;
  }
  A &operator=(int &) {
    cout << "A operator=(int&)" << id << endl;
    return *this;
  }
  A &operator=(int &&) {
    cout << "A operator=(int&&)" << id << endl;
    return *this;
  }
  int a = 1;
  int b = {2};
  int c{2};
  // int d(2);
  B b1{};
  B b2{12};
  // B b2(12);
  B b3{b1};
  // B b3(b1);
};
int A::counter = 0;
class temp {
 public:
  operator float() const {
    cout << "temp operator float() const" << endl;
    return 1.;
  }
};

class Widget {
 public:
  Widget() { cout << "1- Widget()" << endl; }
  Widget(int i, bool b) { cout << "1- Widget(int i, bool b)" << endl; }
  Widget(int i, double d) { cout << "2- Widget(int i, double d)" << endl; }
  Widget(std::initializer_list<long double> il) {
    cout << "3- Widget(std::initializer_list<long double> il)" << endl;
  }
  operator temp() const {
    cout << "Widget operator temp() const" << endl;
    return temp{};
  }
};
int main(int argc, char const *argv[]) {
  cout << "begin" << endl;
  {
    cout << "1" << endl;
    A a;
    cout << "2" << endl;
    A b;
    cout << "3" << endl;
    A c = a;
    cout << "4" << endl;
    c = a;
    cout << "5" << endl;
    c = move(a);
    cout << "6" << endl;
    c = 12;
    cout << "7" << endl;
    int int_b = 12;
    c = int_b;
    cout << "8" << endl;
    A d(a);
    cout << "9" << endl;
    A e{a};
    cout << "10" << endl;
    A f{1, 2, 3};
    cout << "11" << endl;
    A g(1, 2, 3);
    cout << "12" << endl;
    A h = {1, 2, 3};
    cout << "13" << endl;
    A a1 = A{h};
    cout << "14" << endl;
    A a2 = A(1, 2, 3);
    cout << "15" << endl;
    A a3 = *(new A);
    cout << "16" << endl;
    A a4 = *(new A());
    cout << "17" << endl;
    A a5 = *(new A{});
    cout << "18" << endl;
    A a6 = *(new A(1, 2, 3));
    cout << "19" << endl;
    A a7(2.);
    cout << "20" << endl;
    A a8(2.f);
    cout << "21" << endl;
    // A a9(2);
    cout << "22" << endl;
    A a10{2.};
    cout << "23" << endl;
    A a11{2.f};
    cout << "24" << endl;
    // A a12{2};
    cout << "25" << endl;
    int ia1 = 1;
    cout << "26" << endl;
    int ia2 = {1};
    cout << "27" << endl;
    int ia3{3};
    cout << "25" << endl;
    int ia4(3);
    cout << "26" << endl;
    int ia5 = 12.;
    cout << "27" << endl;
    // int ia6 = {12.};  // "narrowing conversion of ‘1.2e+1’ from ‘double’ to
    // ‘int’[-Wnarrowing]",
    cout << "28" << endl;
    // int ia7{12.}; //  "narrowing conversion of ‘1.2e+1’ from ‘double’ to
    // ‘int’
    // [-Wnarrowing]",
    cout << "29" << endl;
    int ia8(12.);
    cout << "30" << endl;

    double d__1{1l};
    auto i_l_1 = {12, 13, 14, 15};
    auto i_l_2 = {12l, 13l, 14l, 15l};
    cout << "31" << endl;
    atomic<int> a_b_1;
    atomic<int> a_b_2{1};
    atomic<int> a_b_3(2);
    atomic<int> a_b_4 = {3};
    atomic<int> a_b_5 = 4;  // Dont Use
    std::cout << a_b_1 << " " << a_b_2 << " " << a_b_3 << " " << a_b_4 << " "
              << a_b_5 << " " << endl;
  }
  cout << "-------------" << endl;
  cout << "-- 1 --" << endl;
  Widget w1(10, true);
  cout << "-- 2 --" << endl;
  Widget w2{10, true};
  cout << "-- 3 --" << endl;
  Widget w4{10, 5.0, 'a', 10.l};
  cout << "-- 4 --" << endl;
  Widget w3(10, 5.0);
  cout << "-- 5 --" << endl;
  Widget w5(w4);
  cout << "-- 6 --" << endl;
  Widget w6{w4,w1,w2,w3};
  cout << "end" << endl;

  return 0;
}
