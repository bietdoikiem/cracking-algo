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

string Solution(vector<string>& passwords, string c, int k) {
  int lessCount = 0, validCount = 0, cLen = (int)c.size();
  for (auto& p : passwords) {
    int l = (int)p.size();
    if (l > cLen) {
      continue;
    } else if (l < cLen) {
      lessCount++;
    }
    validCount++;
  }
  string best = to_string((lessCount / k) * 5 + lessCount + 1);
  string worst = to_string((validCount - 1) / k * 5 + validCount);
  return best + " " + worst;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // Parse inputs
  int n, k;
  cin >> n >> k;
  vector<string> passwords(n);
  for (int i = 0; i < n; i++) cin >> passwords[i];
  string c;
  cin >> c;  // Correct password
  // Output solution
  cout << Solution(passwords, c, k) << endl;
  return 0;
}