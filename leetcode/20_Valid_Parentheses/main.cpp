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

bool isValid(string s) {
  stack<char> stk;
  char b;
  for (auto& c : s) {
    switch (c) {
      // Open brackets
      case '(':
        stk.push(c);
        break;
      case '[':
        stk.push(c);
        break;
      case '{':
        stk.push(c);
        break;
      // Closing brackets
      case ')':
        if (stk.empty()) return false;
        b = stk.top(), stk.pop();
        if (b != '(') return false;
        break;
      case ']':
        if (stk.empty()) return false;
        b = stk.top(), stk.pop();
        if (b != '[') return false;
        break;
      case '}':
        if (stk.empty()) return false;
        b = stk.top(), stk.pop();
        if (b != '{') return false;
        break;
    }
  }
  if (!stk.empty()) return false;
  return true;
}

int main() {
  cout << boolalpha;
  string s1 = "()[]{}";  // true
  cout << "res1: " << isValid(s1) << endl;
  string s2 = "(]";  // false
  cout << "res2: " << isValid(s2) << endl;
  return 0;
}