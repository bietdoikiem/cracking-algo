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

int T, N, M, J, p, res;

void Solves() {
  cin >> T;
  while (T--) {
    cin >> N >> M;
    res = 0;
    queue<pair<int, int>> q;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < N; i++) {
      cin >> p;
      q.push({p, i});
      pq.push(p);
    }
    while (!q.empty() && !pq.empty()) {
      pair<int, int> f = q.front();
      int t = pq.top();
      q.pop();
      if (f.first == t) {
        pq.pop();
        res++;
        if (f.second == M) break;
      } else {
        q.push(f);
      }
    }
    cout << res << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}