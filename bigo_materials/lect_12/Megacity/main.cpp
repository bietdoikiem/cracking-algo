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

const int EPSILON = 0.000001, REQUIRED_POP = 1e6;

int n, s, k, x, y, p;

void Solves() {
  cin >> n >> s;
  p = s;
  vector<pair<ll, ll>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> k;
    v[i] = {pow(x, 2) + pow(y, 2), k};
    s += k;
  }
  if (s < REQUIRED_POP) {
    cout << "-1" << endl;
    return;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    p += v[i].second;
    if (p >= REQUIRED_POP) {
      cout << setprecision(8) << sqrt(v[i].first) << endl;
      break;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}