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
  vector<int> s1, s2;
  if (n == 1 || n == 2) {
    cout << "NO" << endl;
    return;
  } else if (n == 3) {
    s1.push_back(1), s1.push_back(2);
    s2.push_back(3);
    int n1 = (int)s1.size(), n2 = (int)s2.size();
    cout << "YES" << endl;
    cout << n1 << endl;
    for (int i = 0; i < n1; i++) cout << s1[i] << " ";
    cout << n2 << endl;
    for (int i = 0; i < n2; i++) cout << s2[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  Solves(n);
  return 0;
}