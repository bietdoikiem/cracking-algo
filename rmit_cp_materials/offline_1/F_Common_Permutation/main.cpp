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

string s1, s2;

void Solves() {
  while (getline(cin, s1)) {
    getline(cin, s2);
    string ans;
    int count1[26] = {0}, count2[26] = {0};
    for (auto& c : s1) count1[c - 'a'] += 1;
    for (auto& c : s2) count2[c - 'a'] += 1;
    for (int i = 0; i < 26; i++) {
      if (count1[i] && count2[i]) {
        for (int j = 0; j < min(count1[i], count2[i]); j++) {
          ans.push_back(i + 'a');
        }
      }
    }
    cout << ans << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}