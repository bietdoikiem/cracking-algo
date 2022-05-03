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

int absDiff(int x, int y) { return abs(x - y); }

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  int n = (int)arr.size(), l = 0, r = n - k, m = 0;
  while (l < r && (m + k) < n) {
    m = l + (r - l) / 2;
    if (absDiff(arr[m], x) < absDiff(arr[m + k], x)) {
      r = m;
    } else if (absDiff(arr[m], x) > (absDiff(arr[m + k], x))) {
      l = m + 1;
    } else {
      if (arr[m] == arr[m + k] && x - arr[m] > 0) {
        l = m + 1;
      } else {
        r = m;
      }
    }
  }
  vector<int> res(arr.begin() + l, arr.begin() + l + k);
  return res;
}

int main() {
  vector<int> a1 = {1, 2, 3, 4, 5};
  int k1 = 4;
  int x1 = 3;
  cout << "res1: " << findClosestElements(a1, k1, x1) << endl;  // [1,2,3,4]
  vector<int> a2 = {1, 19, 20, 23, 24};
  int k2 = 3;
  int x2 = 21;
  cout << "res2: " << findClosestElements(a2, k2, x2) << endl;  // [20, 23, 24]
  vector<int> a3 = {2};
  int k3 = 1;
  int x3 = 21;
  cout << "res3: " << findClosestElements(a3, k3, x3) << endl;  // [2]
  vector<int> a4 = {1, 2, 3, 4, 5};
  int k4 = 4;
  int x4 = -1;
  cout << "res4: " << findClosestElements(a4, k4, x4) << endl;  // [1,2,3,4]
  vector<int> a5 = {1, 1, 2, 2, 2, 2, 2, 3, 3};
  int k5 = 3;
  int x5 = 3;
  cout << "res5: " << findClosestElements(a5, k5, x5) << endl;  // [2,3,3]
  vector<int> a6 = {1, 2, 3, 4, 4, 4, 4, 5, 5};
  int k6 = 3;
  int x6 = 3;
  cout << "res6: " << findClosestElements(a6, k6, x6) << endl;  // [2,3,4]
  return 0;
}