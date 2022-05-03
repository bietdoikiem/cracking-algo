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
  for (auto y : x) os << y << " ";
  return os << "}";
}

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

/***** SOLUTION BELOW HERE *****/

int findPeakElement(vector<int>& nums) {
  int n = (int)nums.size();
  int l = 0, r = n - 1, m = 0, res = 0;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] > nums[m + 1]) {
      r = m - 1, res = m;
    } else {
      l = m + 1;
    }
  }
  return res;
}

int main() {
  vector<int> n1 = {1, 2, 3, 1};
  cout << "res1: " << findPeakElement(n1) << endl;
  return 0;
}