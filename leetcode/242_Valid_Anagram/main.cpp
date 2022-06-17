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

int letters[26];

bool isAnagram(string s, string t) {
  int n = 0;
  for (auto& c : s) letters[c - 'a']++, n++;
  for (auto& c : t) {
    letters[c - 'a']--, n--;
    if (letters[c - 'a'] < 0) return false;
  }
  return n == 0 ? true : false;
}

int main() {
  cout << boolalpha;
  string s1 = "anagram", t1 = "nagaram";
  cout << "res1: " << isAnagram(s1, t1) << endl;
  string s2 = "rat", t2 = "car";
  cout << "res2: " << isAnagram(s2, t2) << endl;
  return 0;
}