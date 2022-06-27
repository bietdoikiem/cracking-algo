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

string Solution(string S, string T) {
  int n = (int)S.size();
  bool flag;
  string res = S;
  for (int i = n - 1; i >= 0; i--) {
    if (S[i] != 'z') {
      res[i]++;
      flag = true;
      break;
    } else {
      res[i] = 'a';
    }
  }
  if (!flag || res >= T) return "No such string";
  return res;
}

int main() {
  string S, T;
  cin >> S;
  cin >> T;
  cout << Solution(S, T) << endl;
  return 0;
}