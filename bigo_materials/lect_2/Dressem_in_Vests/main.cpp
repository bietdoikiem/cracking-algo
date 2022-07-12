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

void Solves(vector<int>& soldiers, vector<int>& vests, int N, int M, int X,
            int Y) {
  int p = 0, q = 0;
  vector<pair<int, int>> fits;
  while (p < N && q < M) {
    int lower = soldiers[p] - X, upper = soldiers[p] + Y;
    if (vests[q] >= lower && vests[q] <= upper) {
      fits.push_back({p + 1, q + 1});
      p++, q++;
    } else if (vests[q] < lower) {
      q++;
    } else if (vests[q] > upper) {
      p++;
    }
  }
  cout << fits.size() << endl;
  for (auto& p : fits) cout << p.first << " " << p.second << endl;
  return;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> soldiers(N), vests(M);
  for (int i = 0; i < N; i++) cin >> soldiers[i];
  for (int i = 0; i < M; i++) cin >> vests[i];
  Solves(soldiers, vests, N, M, X, Y);
  return 0;
}