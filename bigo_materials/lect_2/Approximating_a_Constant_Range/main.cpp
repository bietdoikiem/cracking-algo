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

void Solves(int points[], int N) {
  int l = 0, r = 0, res = 0, curMin = INT_MAX, curMax = 0;
  unordered_map<int, int> map;
  while (r < N) {
    map[points[r]] = r;
    curMax = max(curMax, points[r]);
    curMin = min(curMin, points[r]);
    if (curMax - curMin > 1) {
      if (map[curMax] > map[curMin]) {
        l = map[curMin] + 1;
        curMin++;
      } else {
        l = map[curMax] + 1;
        curMax--;
      }
    }
    res = max(res, r - l + 1);
    r++;
  }
  cout << res << endl;
  return;
}

int main() {
  int N;
  scanf("%d", &N);
  int points[N];
  for (int i = 0; i < N; i++) scanf("%d", &points[i]);
  Solves(points, N);
  return 0;
}