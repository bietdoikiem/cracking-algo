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

string Solution(vector<int>& minutes, int T, int N) {
  int l = 0, r = 0, res = 0, used = 0;
  while (r < N) {
    int t = used + minutes[r];
    if (t <= T) {
      used = t;
      res = max(res, r - l + 1);
      r++;
    } else {
      if (l != r) {
        used -= minutes[l];
      } else {
        r++;
      }
      l++;
    }
  }
  return to_string(res);
}

int main() {
  // Parse input
  int N, T;
  cin >> N >> T;
  vector<int> mins(N);
  for (int i = 0; i < N; i++) cin >> mins[i];
  // Solution
  cout << Solution(mins, T, N) << endl;
  return 0;
}