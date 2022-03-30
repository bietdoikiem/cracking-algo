#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

ostream& operator<<(ostream& os, pair<int, int> const& x) {
  os << x.first << ", " << x.second;
  return os;
}

template <class T>
ostream& operator<<(ostream& os, vector<T> const& x) {
  os << "{ ";
  for (auto& y : x) os << y << " ";
  return os << "}";
}

// twoSum returns an array of two indices whose elements made up of the target
vector<int> twoSum(vector<int>& numbers, int target) {
  int n = numbers.size();
  int l = 0;
  int r = n - 1;
  int curSum = 0;
  while (l < r) {
    curSum = numbers[l] + numbers[r];
    if (curSum < target) {
      l++;
    } else if (curSum > target) {
      r--;
    } else {
      return {l + 1, r + 1};
    }
  }
  return {};
}

int main() {
  vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  cout << twoSum(numbers, target) << endl;
  return 0;
}