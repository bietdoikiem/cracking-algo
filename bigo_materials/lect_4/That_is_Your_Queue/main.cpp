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

int P, C, caseOrd, pos, tmp;
char cmd;
list<int> l;

void init() {
  l.clear();
  for (int i = 1; i <= min(P, 1000); i++) l.push_back(i);
}

int main() {
  freopen("input.txt", "r", stdin);
  while (cin >> P >> C && P && C) {
    caseOrd++;
    cout << "Case " << caseOrd << ": " << endl;
    init();
    for (int i = 0; i < C; i++) {
      cin >> cmd;
      if (cmd == 'N') {
        tmp = l.front();
        cout << tmp << endl;
        l.pop_front();
        l.push_back(tmp);
      } else {
        cin >> pos;
        if (pos <= 1000) l.remove(pos);
        l.push_front(pos);
      }
    }
  }
  return 0;
}