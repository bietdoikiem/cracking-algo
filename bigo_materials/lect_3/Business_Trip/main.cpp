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

int months[12];

void Solves(int k) {
  int res = 0;
  sort(months, months + 12, greater<int>());
  for (int i = 0; i < 12; i++) {
    if (k <= 0) {
      break;
    } else {
      k -= months[i], res++;
    }
  }
  if (k > 0) res = -1;
  cout << res << endl;
  return;
}

int main() {
  int k;
  cin >> k;
  for (int i = 0; i < 12; i++) cin >> months[i];
  Solves(k);
  return 0;
}