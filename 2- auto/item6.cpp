// Use the explicitly typed initializer idiom when auto deduces undesired types.

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  {
    std::vector<int> int_v{100, 0};
    std::vector<bool> bool_v(100, false);

    auto a_i_v_t = int_v[1];
    auto &a_i_v_t_r = int_v[1];
    cout << "1 Begin -------" << endl;
    cout << "1: " << int_v[1] << " " << a_i_v_t << endl;
    a_i_v_t = 12;
    cout << "2: " << int_v[1] << " " << a_i_v_t << endl;
    cout << "3: " << int_v[1] << " " << a_i_v_t_r << endl;
    a_i_v_t_r = 12;
    cout << "4: " << int_v[1] << " " << a_i_v_t_r << endl;
    cout << "1 End -------" << endl;

    cout << "2 Begin -------" << endl;
    auto a_b_v_t = bool_v[1];
    // auto &a_b_v_t_r = bool_v[1];
    cout << "1: " << bool_v[1] << " " << a_b_v_t << endl;
    a_b_v_t = true;
    cout << "2: " << bool_v[1] << " " << a_b_v_t << endl;
    // cout << "3: " << bool_v[1] << " " << a_b_v_t_r << endl;
    //  a_b_v_t_r = true;
    //  cout << "2: " << bool_v[1] << " " << a_b_v_t_r << endl;
    cout << "2 End -------" << endl;
  }
  return 0;
}