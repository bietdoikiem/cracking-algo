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

const int MAX = 10001;
int N, M, A, B, res;
bool visited[MAX];
vector<int> adj[MAX];

int maxImpact(int s) {
  int cnt = 1;
  visited[s] = true;
  for (int i = 0; i < (int)adj[s].size(); i++) {
    int v = adj[s][i];
    if (!visited[v]) cnt += maxImpact(v);
  }
  return cnt;
}

void Solves() {
  for (int i = 1; i < N + 1; i++) {
    if (!visited[i]) {
      res = max(res, maxImpact(i));
      for (int i = 1; i < N + 1; i++) visited[i] = false;
    }
  }
  cout << res << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N >> M;
  while (M--) {
    cin >> A >> B;
    adj[A].push_back(B);
  }
  Solves();
  return 0;
}