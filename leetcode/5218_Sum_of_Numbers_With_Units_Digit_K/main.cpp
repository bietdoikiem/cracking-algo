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

int dp[3001];

int minimumNumbers(int num, int k) {
  if (num == 0) return 0;
  vector<int> validNums;
  // Build nums with valid digit k
  for (int i = k; i <= num; i += 10) validNums.push_back(i);
  cout << "validNums: " << validNums << endl;
  fill_n(dp, size(dp), INT_MAX);
  // Fill valid minimum way based on valid nums
  for (auto& c : validNums) dp[c] = 1;
  for (int a = 1; a <= num; a++) {
    for (auto& c : validNums) {
      if (a - c > 0) {
        if (dp[a - c] != INT_MAX) {
          dp[a] = min(dp[a], 1 + dp[a - c]);
        }
      }
    }
  }
  if (dp[num] != INT_MAX) {
    return dp[num];
  }
  return -1;
}

int main() {
  int n1 = 58, k1 = 9;  // 2
  cout << "res1: " << minimumNumbers(n1, k1) << endl;
  int n2 = 37, k2 = 2;  // -1
  cout << "res2: " << minimumNumbers(n2, k2) << endl;
  int n3 = 0, k3 = 7;  // 0
  cout << "res3: " << minimumNumbers(n3, k3) << endl;
  int n4 = 1, k4 = 1;  // 1
  cout << "res4: " << minimumNumbers(n4, k4) << endl;
  return 0;
}