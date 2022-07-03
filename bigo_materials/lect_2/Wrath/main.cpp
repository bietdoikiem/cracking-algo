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

void Solves(int lengths[], int n) {
  int r = n - 1, res = 0, bound = n;
  while (r >= 0) {
    if (r < bound) res++;
    bound = min(bound, r - lengths[r]);
    r--;
  }
  cout << res << endl;
}

int main() {
  int n;
  scanf("%d", &n);
  int lengths[n];
  for (int i = 0; i < n; i++) scanf("%d", &lengths[i]);
  Solves(lengths, n);
  return 0;
}