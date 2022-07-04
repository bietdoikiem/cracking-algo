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

void Solves(vector<pair<int, int>>& p) {
  sort(p.begin(), p.end(),
       [](const pair<int, int>& a, const pair<int, int>& b) {
         return (a.first < b.first) ||
                (a.first == b.first && a.second < b.second);
       });
  if (p[0].first == p[1].first && p[1].first == p[2].first &&
      p[2].first != p[3].first && p[3].first == p[4].first &&
      p[4].first != p[5].first && p[5].first == p[6].first &&
      p[6].first == p[7].first && p[0].second == p[3].second &&
      p[3].second == p[5].second && p[5].second != p[1].second &&
      p[1].second == p[6].second && p[6].second != p[2].second &&
      p[2].second == p[4].second && p[4].second == p[7].second) {
    cout << "respectable" << endl;
  } else {
    cout << "ugly" << endl;
  }
  return;
}

int main() {
  vector<pair<int, int>> p(8);
  for (int i = 0; i < 8; i++) cin >> p[i].first >> p[i].second;
  Solves(p);
  return 0;
}