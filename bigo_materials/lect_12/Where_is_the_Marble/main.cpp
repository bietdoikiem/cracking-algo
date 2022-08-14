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

#define MAX 10005
int T, N, Q, q, nums[MAX];

int bs() {
  int l = 0, r = N - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] == q) {
      return m;
    } else if (nums[m] < q) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}

void Solves() {
  while (cin >> N >> Q && N && Q) {
    T++;
    unordered_map<int, int> map;
    for (int i = 0; i < N; i++) cin >> nums[i];
    sort(nums, nums + N);
    for (int i = 0; i < N; i++) {
      if (map.find(nums[i]) == map.end()) map[nums[i]] = i + 1;
    }
    cout << "CASE# " << T << ":" << endl;
    while (Q--) {
      cin >> q;
      int ans = bs();
      if (ans != -1) {
        cout << q << " found at " << map[nums[ans]] << endl;
      } else {
        cout << q << " not found" << endl;
      }
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}