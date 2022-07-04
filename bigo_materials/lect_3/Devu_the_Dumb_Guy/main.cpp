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

void Solves(vector<ll>& subs, int x) {
  ll res = 0;
  sort(subs.begin(), subs.end());
  for (auto& s : subs) {
    res += x * s;
    x = max(1, x - 1);
  }
  cout << res << endl;
  return;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<ll> subs(n);
  for (int i = 0; i < n; i++) cin >> subs[i];
  Solves(subs, x);
  return 0;
}