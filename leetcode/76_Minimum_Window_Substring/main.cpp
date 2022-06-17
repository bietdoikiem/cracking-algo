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

pair<int, int> minDist(pair<int, int> p1, pair<int, int> p2) {
  int d1 = p1.second - p1.first, d2 = p2.second - p2.first;
  return d1 < d2 ? p1 : p2;
}

// minWindow returns the minimum window contains all the t substring's letters
string minWindow(string s, string t) {
  int m = (int)s.size(), n = (int)t.size(), l = 0, r = 0, charCount = 0;
  pair<int, int> minW = {0, UPPER_BOUND};
  unordered_map<char, int> letters;
  // Build dict on t's letters
  for (int i = 0; i < n; i++) {
    if (letters.find(t[i]) == letters.end()) {
      letters[t[i]] = 1;
      continue;
    }
    letters[t[i]]++;
  }
  // Sliding through s
  while (l <= r) {
    if (charCount < n && r < m) {
      if (letters.find(s[r]) != letters.end()) {
        if (letters[s[r]] > 0) charCount++;
        letters[s[r]]--;
      }
      r++;
      continue;
    }
    if (charCount == n) minW = minDist(minW, {l, r});
    if (letters.find(s[l]) != letters.end()) {
      if (letters[s[l]] >= 0) charCount--;
      letters[s[l]]++;
    }
    l++;
  }
  if (minW.second == UPPER_BOUND) return "";  // Invalid one
  return s.substr(minW.first, (minW.second - 1) - minW.first + 1);
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