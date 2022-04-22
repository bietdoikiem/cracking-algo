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

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto& y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

int dp[101];

int rob(vector<int>& nums) {
  int n = (int)nums.size();
  dp[1] = nums[0];
  for (int i = 2; i < n + 1; i++)
    dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
  return dp[n];
}

int main() {
  vector<int> n1 = {1, 2, 3, 1};
  cout << "ans1: " << rob(n1) << endl;
  vector<int> n2 = {2, 7, 9, 3, 1};
  cout << "ans2: " << rob(n2) << endl;
  return 0;
}