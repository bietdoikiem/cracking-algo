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

void Solves(vector<int>& ratings, int n) {
  for (int i = 0; i < n; i++) {
    int r = 1;
    for (int j = 0; j < n; j++) {
      if (ratings[i] < ratings[j]) r++;
    }
    cout << r << " ";
  }
  cout << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  vector<int> ratings(n);
  for (int i = 0; i < n; i++) cin >> ratings[i];
  Solves(ratings, n);
  return 0;
}