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

int uppers[26];
int lowers[26];

string greatestLetter(string s) {
  string res;
  int maxChar = -1;
  for (auto& c : s) {
    if (islower(c)) {
      lowers[c - 'a']++;
    } else {
      uppers[c - 'A']++;
    }
  }
  // Traverse and find greatest one
  for (int i = 0; i < 26; i++) {
    if (uppers[i] && lowers[i]) maxChar = i;
  }
  if (maxChar == -1) return "";
  res.push_back((char)(maxChar + 'A'));
  return res;
}

int main() {
  string s1 = "lEeTcOdE";
  cout << "res1: " << greatestLetter(s1) << endl;
  return 0;
}