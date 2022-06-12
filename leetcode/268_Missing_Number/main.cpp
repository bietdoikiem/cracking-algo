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

int missingNumber(vector<int>& nums) {
  int n = (int)nums.size(), i = 0;
  // Cycle sort (Time complexity: O(n))
  while (i < n) {
    if (nums[i] < n && nums[i] != i) {
      swap(nums[nums[i]], nums[i]);
    } else {
      i++;
    }
  }
  // Find missing number
  for (int i = 0; i < n; i++)
    if (nums[i] != i) return i;
  return n;
}

int main() {
  // TODO: Solve the problem!
  return 0;
}