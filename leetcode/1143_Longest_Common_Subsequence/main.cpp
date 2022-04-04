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

int max(int x, int y) { return x > y ? x : y; }

int helper(string text1, string text2, size_t i, size_t j) {
  if (i >= text1.size() || j >= text2.size()) {
    return 0;
  }
  if (text1[i] == text2[j]) {
    return 1 + helper(text1, text2, i + 1, j + 1);
  }
  return max(helper(text1, text2, i + 1, j), helper(text1, text2, i, j + 1));
}

int longestCommonSubsequence(string text1, string text2) {
  int ans = helper(text1, text2, 0, 0);
  return ans;
}

int main() {
  // TODO: Solve the problem!
  string text1 = "abcde";
  string text2 = "ace";
  cout << "LCS of text1 and text1 is: "
       << longestCommonSubsequence(text1, text2) << endl;
  text1 = "abc";
  text2 = "abc";
  cout << "LCS of text1 and text1 is: "
       << longestCommonSubsequence(text1, text2) << endl;
  text1 = "abc";
  text2 = "def";
  cout << "LCS of text1 and text1 is: "
       << longestCommonSubsequence(text1, text2) << endl;
  return 0;
}