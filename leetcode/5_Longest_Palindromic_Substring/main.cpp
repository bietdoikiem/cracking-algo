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

bool dp[1000][1000];

string longestPalindrome(string s) {
  int n = (int)s.size(), maxLen = 0, mi = 0;
  // Handle base case with 1 letter
  for (int i = 0; i < n; i++) dp[i][i] = true, maxLen = 1;
  // Handle base case with 2 letters
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) dp[i][i + 1] = true, maxLen = 2, mi = i;
  }
  // Handle case with >= 3 letters
  for (int i = n - 3; i >= 0; i--) {
    for (int j = i + 2; j < n; j++) {
      if (s[i] == s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;
        int len = j - i + 1;
        if (len > maxLen) maxLen = len, mi = i;
      };
    }
  }
  string res = s.substr(mi, maxLen);
  return res;
}

int main() {
  string s1 = "babad";
  cout << "res1: " << longestPalindrome(s1) << endl;
  memset(dp, false, sizeof(dp));
  string s2 = "bacca";
  cout << "res2: " << longestPalindrome(s2) << endl;
  memset(dp, false, sizeof(dp));
  string s3 = "b";
  cout << "res3: " << longestPalindrome(s3) << endl;
  memset(dp, false, sizeof(dp));
  string s4 = "aa";
  cout << "res4: " << longestPalindrome(s4) << endl;
  memset(dp, false, sizeof(dp));
  string s5 = "cbbd";
  cout << "res5: " << longestPalindrome(s5) << endl;
  memset(dp, false, sizeof(dp));
  string s6 = "aaaaa";
  cout << "res6: " << longestPalindrome(s6) << endl;
  memset(dp, false, sizeof(dp));
  string s7 = "cyz";
  cout << "res7: " << longestPalindrome(s7) << endl;
  return 0;
}