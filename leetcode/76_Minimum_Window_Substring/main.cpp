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

int UPPER_BOUND = 100000;

// minWindow returns the minimum window contains all the t substring's letters
string minWindow(string s, string t) {
  int m = (int)s.size(), n = (int)t.size(), l = 0, r = 0, charCount = 0;
  pair<pair<int, int>, int> mw = {{0, 0}, UPPER_BOUND};
  unordered_map<char, int> map;
  // Build dict
  for (auto& c : t) map[c] = map.find(c) != map.end() ? map[c] + 1 : 1;
  // Sliding through s
  while (l <= r) {
    // Shift right
    if (charCount < n && r < m) {
      if (map.find(s[r]) != map.end()) {
        if (map[s[r]] > 0) charCount++;
        map[s[r]]--;
      }
      r++;
      continue;
    }
    // Find valid minimum window
    if (charCount == n) {
      int len = r - l + 1;
      if (len < mw.second)
        mw.first.first = l, mw.first.second = r, mw.second = len;
    };
    // Shift left
    if (map.find(s[l]) != map.end()) {
      if (map[s[l]] >= 0) charCount--;
      map[s[l]]++;
    }
    l++;
  }
  if (mw.second == UPPER_BOUND) return "";
  return s.substr(mw.first.first, mw.second - 1);
}

int main() {
  string s1 = "ACOCB", t1 = "CB";
  cout << "res1: " << minWindow(s1, t1) << endl;
  string s2 = "ADOBECODEBANC", t2 = "ABC";
  cout << "res2: " << minWindow(s2, t2) << endl;
  string s3 = "a", t3 = "a";
  cout << "res3: " << minWindow(s3, t3) << endl;
  string s4 = "a", t4 = "aa";
  cout << "res4: " << minWindow(s4, t4) << endl;
  return 0;
}