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

int longestConsecutiveSequence(vector<int>& nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  int res = 0;
  for (auto& e : nums) {
    if (s.find(e) == s.end()) continue;
    s.erase(e);
    int prev = e - 1;
    int next = e + 1;
    while (s.find(prev) != s.end()) s.erase(prev--);
    while (s.find(next) != s.end()) s.erase(next--);
    res = max(res, next - prev - 1);
  }
  return res;
}

int main() {
  vector<int> n1 = {100, 4, 200, 1, 3, 2};
  cout << "res1: " << longestConsecutiveSequence(n1) << endl;
  vector<int> n2 = {};
  cout << "res2: " << longestConsecutiveSequence(n2) << endl;
  return 0;
}