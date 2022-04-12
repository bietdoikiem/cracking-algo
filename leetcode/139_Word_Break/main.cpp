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

int dp[1000];
bool dp2[1001];

bool helper(string& s, size_t n, size_t l, unordered_map<string, int>& m) {
  if (l >= n) {
    return false;
  }
  if (dp[l] != -1) {
    return dp[l] == 1 ? true : false;
  }
  for (size_t i = 1; l + i <= n; i++) {
    // string substr = s.substr(l, i);
    // LOG(substr, l, i);
    if (m.find(s.substr(l, i)) != m.end()) {
      if (l + i == n) {
        dp[l] = 1;
        return true;
      }
      if (helper(s, n, l + i, m)) {
        return true;
      }
    }
  }
  dp[l] = 0;
  return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
  memset(dp, -1, sizeof(dp));
  unordered_map<string, int> wordMap;
  for (size_t i = 0; i < wordDict.size(); i++) {
    wordMap[wordDict[i]] = i;
  }
  return helper(s, s.size(), 0, wordMap);
}

bool checkKey(unordered_map<string, bool>& m, string key) {
  if (m.find(key) != m.end()) {
    return true;
  }
  return false;
}

bool wordBreakDP(string s, vector<string>& wordDict) {
  int n = (int)s.size();
  unordered_map<string, bool> m;
  for (int i = 0; i < (int)wordDict.size(); i++) {
    m[wordDict[i]] = true;
  }
  dp2[0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp2[j] && checkKey(m, s.substr(j, i - j))) {
        dp2[i] = true;
        break;
      }
    }
  }
  return dp2[n];
}

int main() {
  cout << boolalpha;
  string s1 =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaab";
  vector<string> dict1 = {"a",         "aa",        "aaa",     "aaaa",
                          "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                          "aaaaaaaaa", "aaaaaaaaaa"};
  cout << "Result of s1: " << wordBreakDP(s1, dict1) << endl;
  string s2 = "leetcode";
  vector<string> dict2 = {"leet", "code"};
  cout << "Result of s2: " << wordBreakDP(s2, dict2) << endl;
  return 0;
}