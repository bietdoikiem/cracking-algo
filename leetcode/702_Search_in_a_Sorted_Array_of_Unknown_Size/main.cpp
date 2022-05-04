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

class ArrayReader {
 public:
  int get(int index);
};

int search(ArrayReader& reader, int target) {
  int l = 0, r = target - reader.get(0);
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (reader.get(m) < target) {
      l = m + 1;
    } else if (reader.get(m) > target) {
      r = m - 1;
    } else {
      return m;
    }
  }
  return -1;
}

int main() {
  // INTERACTIVE PROBLEM!
  return 0;
}