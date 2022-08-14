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

ll T, N, A, M, st;

void Solves() {
  cin >> T;
  while (T--) {
    set<ll> s;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      cin >> st;
      s.insert(st);
    };
    for (int i = 0; i < M; i++) {
      cin >> st;
      if (s.find(st) != s.end()) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
        s.insert(st);
      }
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}