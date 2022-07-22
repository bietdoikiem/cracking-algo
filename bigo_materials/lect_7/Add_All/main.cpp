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

ll N, num, cost, curSum, t1, t2;

void Solves() {
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  // Add to pq
  for (int i = 0; i < N; i++) {
    cin >> num;
    pq.push(num);
  }
  while (pq.size() > 1) {
    t1 = pq.top(), pq.pop();
    t2 = pq.top(), pq.pop();
    curSum = t1 + t2;
    cost += curSum;
    pq.push(curSum);
  }
  cout << cost << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  while (cin >> N && N) {
    cost = 0;
    Solves();
  }
  return 0;
}