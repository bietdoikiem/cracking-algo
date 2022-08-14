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

#define MAX 55
const int INF = 1e9 + 5;
int T, M, resID, resP, dist[MAX][MAX];

void Floyd() {
  for (int k = 0; k < M; k++) {
    for (int i = 0; i < M; i++) {
      if (dist[i][k] == INF) continue;
      for (int j = 0; j < M; j++) {
        if (dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

void Solves() {
  string line;
  cin >> T;
  while (T--) {
    resID = 0, resP = 0;
    cin >> line, M = line.size();
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < M; j++) {
        if (i == j) {
          dist[i][j] = 0;
        } else if (line[j] == 'Y') {
          dist[i][j] = 1;
        } else {
          dist[i][j] = INF;
        }
      }
      if (i < M - 1) cin >> line;
    }
    Floyd();
    for (int i = 0; i < M; i++) {
      int count = 0;
      for (int j = 0; j < M; j++) {
        if (dist[i][j] == 2) count++;
      }
      if (count > resP) {
        resP = count;
        resID = i;
      } else if (count == resP) {
        resID = min(i, resID);
      }
    }
    cout << resID << " " << resP << endl;
  }
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}