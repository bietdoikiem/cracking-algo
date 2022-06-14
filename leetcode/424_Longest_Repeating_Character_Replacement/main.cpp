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

// Sliding window approach -> O(n) of Time complexity, O(26) Space
int freq[26];

int charToIdx(char c) { return (int)c - 65; }

int characterReplacement(string s, int k) {
  int res = 1, n = (int)s.size(), l = 0, r = 0, maxFreq = 1;
  while (r < n) {
    int windowLen = r - l + 1;
    freq[charToIdx(s[r])]++;
    maxFreq = max(maxFreq, freq[charToIdx(s[r])]);
    if (windowLen - maxFreq <= k) {
      res = max(res, windowLen);
    } else {
      freq[charToIdx(s[l])]--;
      l++;
    }
    r++;
  }
  return res;
}

int main() {
  // TODO: Solve the problem!
  return 0;
}