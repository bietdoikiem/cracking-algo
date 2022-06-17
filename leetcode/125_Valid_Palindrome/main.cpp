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

bool isPalindrome(string s) {
  string tmpStr;
  for (auto& c : s) {
    if (iswalnum(c)) tmpStr.push_back(tolower(c));
  }
  int l = 0, r = (int)tmpStr.size() - 1;
  while (l <= r) {
    if (tmpStr[l] != tmpStr[r]) return false;
    l++, r--;
  }
  return true;
}

int main() {
  cout << boolalpha;
  string s1 = "A man, a plan, a canal: Panama";
  cout << "res1: " << isPalindrome(s1) << endl;
  string s2 = "radar";
  cout << "res2: " << isPalindrome(s2) << endl;
  return 0;
}