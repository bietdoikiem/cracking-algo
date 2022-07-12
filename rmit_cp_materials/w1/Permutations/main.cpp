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

void Solves(int n) {
  if (n == 1) {
    cout << "1" << endl;
    return;
  } else if (n == 2 || n == 3) {
    cout << "NO SOLUTION" << endl;
    return;
  }
  // Print even numbers
  for (int i = 2; i <= n; i += 2) {
    cout << i << " ";
  }
  // Print ood numbers
  for (int i = 1; i <= n; i += 2) {
    if (n - i <= 1) {
      cout << i << endl;
    } else {
      cout << i << " ";
    }
  }
  return;
}

int main() {
  int n;
  cin >> n;
  Solves(n);
  return 0;
}