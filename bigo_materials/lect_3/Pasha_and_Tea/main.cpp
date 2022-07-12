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

double EPSILON = 1e-11;
int nums[2000000];

void Solves(int n, double w) {
  int minBoy = INT_MAX, minGirl = INT_MAX;
  sort(nums, nums + 2 * n, greater<int>());
  for (int i = 0; i < n; i++) minBoy = min(nums[i], minBoy);
  for (int i = n; i < 2 * n; i++) minGirl = min(nums[i], minGirl);
  double res = 0.0, l = 0.0, r = minGirl * 1.0;
  while (r - l >= EPSILON) {
    double m = (l + r) / 2.0, mw = m * 2.0, total = m * n + mw * n;
    // LOG(w, l, r, m, mw, total, res);
    if (mw > minBoy || total > w) {
      r = m;
    } else if (mw <= minBoy) {
      res = max(res, total);
      if (w - res < EPSILON) break;
      l = m;
    }
  }
  cout << setprecision(10) << res << endl;
  return;
}

int main() {
  int n;
  double w;
  cin >> n >> w;
  for (int i = 0; i < 2 * n; i++) cin >> nums[i];
  Solves(n, w);
  return 0;
}