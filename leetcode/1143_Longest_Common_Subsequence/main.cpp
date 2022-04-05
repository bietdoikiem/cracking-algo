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

int dp[1000][1000];
int dp2[1001][1001];  // Cache for Bottom-Up approach

int max(int x, int y) { return x > y ? x : y; }

int helper(string text1, string text2, size_t m, size_t n, size_t i, size_t j) {
  if (i == m || j == n) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }
  if (text1[i] == text2[j]) {
    dp[i][j] = 1 + helper(text1, text2, m, n, i + 1, j + 1);
    return dp[i][j];
  }
  dp[i][j] = max(helper(text1, text2, m, n, i + 1, j),
                 helper(text1, text2, m, n, i, j + 1));
  return dp[i][j];
}

// NOTE: TLE flagged in Leetcode submission
int longestCommonSubsequenceMemoization(string text1, string text2) {
  memset(dp, -1, sizeof(dp));  // Set all to -1
  int ans = helper(text1, text2, text1.size(), text2.size(), 0, 0);
  return ans;
}

int longestCommonSubsequence(string text1, string text2) {
  size_t m = text1.size();
  size_t n = text2.size();
  for (size_t i = m - 1; i < m; i--) {
    for (size_t j = n - 1; j < n; j--) {
      // cout << "i: " << i << " - j: " << j << endl;
      if (text1[i] == text2[j]) {
        // cout << "Did it run here?" << endl;
        dp2[i][j] = 1 + dp2[i + 1][j + 1];
      } else {
        // cout << "Did it run again?" << endl;
        dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
      }
    }
  }
  return dp2[0][0];
}

int main() {
  // TODO: Solve the problem!
  string text1 = "quetzalcoatl";
  string text2 = "tezcatlipoca";
  cout << "LCS of text1 and text2 is: "
       << longestCommonSubsequence(text1, text2) << endl;
  text1 = "abc";
  text2 = "abc";
  memset(dp2, 0, sizeof(dp2));  // Reset DP cache
  cout << "LCS of text1 and text2 is: "
       << longestCommonSubsequence(text1, text2) << endl;
  text1 = "abc";
  text2 = "def";
  memset(dp2, 0, sizeof(dp2));
  cout << "LCS of text1 and text2 is: "
       << longestCommonSubsequence(text1, text2) << endl;
  return 0;
}