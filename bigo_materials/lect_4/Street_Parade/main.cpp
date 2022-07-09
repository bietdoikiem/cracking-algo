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

int trucks[1000][1000];
string res[1000];

void Solves(int n, int ord) {
  int cur = 1, r = 0;
  stack<int> s;
  while (r < n) {
    if (trucks[ord][r] == cur) {
      cur++, r++;
    } else {
      if (s.empty() || trucks[ord][r] < s.top()) {
        s.push(trucks[ord][r]), r++;
        continue;
      }
      while (!s.empty()) {
        if (s.top() == cur) {
          s.pop(), cur++;
        } else {
          res[ord] = "no";
          return;
        }
      }
    }
  }
  res[ord] = "yes";
  return;
}

int main() {
  int n = 0, ord = 0;
  while (cin >> n) {
    if (n == 0) break;
    for (int i = 0; i < n; i++) cin >> trucks[ord][i];
    Solves(n, ord);
    ord++;
  }
  for (int i = 0; i < ord; i++) cout << res[i] << endl;
  return 0;
}