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
stack<int> st;
map<char, int> val;

void Solves() {
  for (auto& c : s) {
    if (c == '(' || (c == 'O' || c == 'H' || c == 'C')) {
      st.push(val[c]);
    } else if (c == ')') {
      int v = val[')'], total = 0;
      while (v != val['(']) {
        v = st.top(), st.pop();
        if (v != val['(']) total += v;
      }
      st.push(total);
    } else {  // isdigit
      int v = st.top();
      st.pop();
      st.push(v * (int)(c - '0'));
    }
  }
  int res = 0;
  while (!st.empty()) res += st.top(), st.pop();
  cout << res << endl;
  return;
}

int main() {
  val['C'] = 12, val['H'] = 1, val['O'] = 16, val['('] = -1, val[')'] = 0;
  freopen("input.txt", "r", stdin);
  cin >> s;
  Solves();
  return 0;
}