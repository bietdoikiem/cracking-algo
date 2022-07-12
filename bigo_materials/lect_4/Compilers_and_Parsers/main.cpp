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

string s;

void Solves(stack<int>& st) {
  int res = 0;
  st.push(-1);
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '<') {
      st.push(i);
    } else {
      st.pop();
      if (st.empty()) {
        break;
      } else {
        if (st.top() == -1) res = max(res, i - st.top());
      }
    }
  }
  cout << res << endl;
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    stack<int> st;
    Solves(st);
  }
  return 0;
}