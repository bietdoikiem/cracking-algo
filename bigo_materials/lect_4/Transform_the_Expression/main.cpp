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

string exps[100];

void Solves(int T) {
  stack<char> opStk;
  stack<char> bracketStk;
  for (int i = 0; i < T; i++) {
    string exp;
    for (auto& c : exps[i]) {
      if (c == '(') {
        bracketStk.push(c);
      } else if (c == ')') {
        bracketStk.pop();
        char op = opStk.top();
        opStk.pop();
        exp.push_back(op);
      } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        opStk.push(c);
      } else {
        exp.push_back(c);
      }
    }
    cout << exp << endl;
  }
  cout << endl;
  return;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) cin >> exps[i];
  Solves(T);
  return 0;
}