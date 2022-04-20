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
  for (auto& y : x) os << y << " ";
  return os << "}";
}

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto& y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

int solution(string& S, vector<int>& C) {
  char lchar = '\0';
  int lcost = -1;
  int ans = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if ((lchar == '\0' && lcost == -1) || lchar != S[i]) {
      lchar = S[i];
      lcost = C[i];
      continue;
    }
    if (lcost > C[i]) {
      ans += C[i];
    } else {
      ans += lcost;
      lcost = C[i];
    }
  }
  return ans;
}

int main() {
  string s1 = "abccbd";
  vector<int> c1 = {0, 1, 2, 3, 4, 5};
  cout << "ans1: " << solution(s1, c1) << endl;
  string s2 = "aaab";
  vector<int> c2 = {3, 4, 5, 6};
  cout << "ans2: " << solution(s2, c2) << endl;
  return 0;
}