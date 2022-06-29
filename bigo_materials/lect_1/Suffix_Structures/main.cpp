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

int letters[26];

string Solution(string s, string t) {
  int m = (int)s.size(), n = (int)t.size(), j = 0;
  string res;
  // Check automaton
  for (int i = 0; i < m; i++) {
    if (s[i] == t[j]) j++;
    if (j == n) return "automaton";
  }
  for (auto& c : s) letters[c - 'a']++;
  // Check array
  int charCount = 0;
  for (auto& c : t) {
    if (letters[c - 'a'] == 0) return "need tree";
    charCount++;
    letters[c - 'a']--;
  }
  if (charCount == m) return "array";
  return "both";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // Parse input
  string s, t;
  cin >> s;
  cin >> t;
  // Solution
  cout << Solution(s, t) << endl;
  return 0;
}