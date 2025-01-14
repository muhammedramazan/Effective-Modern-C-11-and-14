// Prefer const_iterators to iterators.

#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[]) {
  const std::vector<int> values;
  values.begin();
  std::begin(values);
  std::cbegin(values);
  values.begin();
  int arr[12];
  const int carr[12]{0};
  std::begin(arr);
  std::cbegin(carr);
  return 0;
}
