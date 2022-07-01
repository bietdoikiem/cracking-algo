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

string Solution(vector<int>& goods, vector<int>& prepares, int N, int M) {
  int res = N, p = 0, q = 0;
  while (p < N && q < M) {
    if (goods[p] <= prepares[q]) {
      p++, q++, res--;
    } else {
      q++;
    }
  }
  return to_string(res);
}

int main() {
  // Parse input
  int N, M;
  cin >> N >> M;
  vector<int> goods(N), prepares(M);
  for (int i = 0; i < N; i++) cin >> goods[i];
  for (int i = 0; i < M; i++) cin >> prepares[i];
  // Solution
  cout << Solution(goods, prepares, N, M) << endl;
  return 0;
}