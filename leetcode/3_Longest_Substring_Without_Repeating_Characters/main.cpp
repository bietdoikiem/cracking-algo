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

int lengthOfLongestSubstring(string s) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int l = 0, r = 0, n = (int)s.size(), ans = 0;
  unordered_map<char, int> umap;
  while (r < n) {
    if (umap.find(s[r]) != umap.end() && umap[s[r]] >= l) {
      l = umap[s[r]] + 1;
    }
    umap[s[r]] = r;
    ans = max(ans, r - l + 1);
    r++;
  }
  return ans;
}

int main() { return 0; }