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

ll n, b, t, d, curTime, pos, res[200000];
pair<ll, ll> query;
pair<ll, pair<ll, ll>> front;
queue<pair<ll, pair<ll, ll>>> q;

void processResult() {
  front = q.front();
  pos = front.first, query = front.second;
  q.pop();
  curTime = max(curTime + query.second, query.first + query.second);
  res[pos] = curTime;
}

void Solves() {
  for (int i = 0; i < n; i++) {
    cin >> t >> d;
    // LOG(curTime, t, d, q.size());
    // Fast forward time
    while (curTime <= t && !q.empty()) processResult();
    if (curTime > t) {
      if ((int)q.size() < b) {
        q.push({i, {t, d}});
      } else {
        res[i] = -1;
      }
    } else {
      curTime = t + d;
      res[i] = curTime;
    }
  }
  // Pop remaining in queue
  while (!q.empty()) processResult();
  // Print answer
  for (int i = 0; i < n; i++) cout << res[i] << " ";
  cout << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> n >> b;
  Solves();
  return 0;
}