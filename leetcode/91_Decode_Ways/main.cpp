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

int numDecodings(string s) {
  int n = (int)s.size();
  dp[0] = 1;
  dp[1] = s.substr(0, 1) != "0" ? 1 : 0;
  for (int i = 2; i < n + 1; i++) {
    if (stoi(s.substr(i - 1, 1)) != 0) dp[i] += dp[i - 1];
    if (s.substr(i - 2, 1) != "0") {
      if (int td = stoi(s.substr(i - 2, 2)); td > 0 && td < 27)
        dp[i] += dp[i - 2];
    }
  }
  return dp[n];
}

int numDecodingsSpaceOptimized(string s) {
  int n = (int)s.size();
  int td = 1;
  int od = s.substr(0, 1) != "0" ? 1 : 0;
  int ans = od;
  for (int i = 2; i < n + 1; i++) {
    ans = 0;
    if (stoi(s.substr(i - 1, 1)) != 0) ans += od;
    if (s.substr(i - 2, 1) != "0") {
      if (int d = stoi(s.substr(i - 2, 2)); d > 0 && d < 27) ans += td;
    }
    td = od;
    od = ans;
  }
  return ans;
}

int main() {
  string s1 = "12";
  cout << "ans1: " << numDecodings(s1) << endl;
  memset(dp, 0, sizeof(dp));  // Reset DP
  string s2 = "226";
  cout << "ans2: " << numDecodings(s2) << endl;
  memset(dp, 0, sizeof(dp));  // Reset DP
  string s3 = "06";
  cout << "ans3: " << numDecodings(s3) << endl;
  string s4 = "27";
  cout << "ans4: " << numDecodings(s4) << endl;
  return 0;
}