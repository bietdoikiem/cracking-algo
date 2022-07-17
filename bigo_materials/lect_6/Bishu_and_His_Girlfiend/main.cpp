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

#define MAX 1001

int N, u, v, s = 1, Q, path[MAX];
bool hasGirl[MAX], visited[MAX];
vector<int> adj[MAX];

void dfs(int s) {
  visited[s] = true;
  for (int i = 0; i < (int)adj[s].size(); i++) {
    int v = adj[s][i];
    if (visited[v] == false) {
      path[v] = s, dfs(v);
    }
  }
  return;
}

int pathLen(int d) {
  if (s == d) return 0;
  if (path[d] == -1) return -MAX;
  return 1 + pathLen(path[d]);
}

void Solves() {
  dfs(s);
  int minLen = MAX, minPos = MAX;
  for (int i = 2; i <= N + 1; i++) {
    int curLen = pathLen(i);
    // LOG(curLen, minLen, i, minPos, hasGirl[i]);
    if (curLen > 0 && hasGirl[i]) {
      if (curLen <= minLen) {
        minPos = curLen == minLen ? min(minPos, i) : i;
        minLen = min(minLen, curLen);
      }
    }
  }
  // LOG(minLen, minPos);
  cout << minPos << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N;  // Num of countries
  for (int i = 1; i <= N + 1; i++) path[i] = -1;
  for (int i = 0; i < N - 1; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int g;
    cin >> g;
    hasGirl[g] = true;
  }
  Solves();
  return 0;
}