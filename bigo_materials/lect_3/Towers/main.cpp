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

int lengths[1000], freq[1001];

void Solves(int N) {
  int res = 0, occ = 0;
  sort(lengths, lengths + N);
  for (int i = 0; i < N; i++) {
    if (freq[lengths[i]] == 0) occ++;
    freq[lengths[i]]++;
    res = max(res, freq[lengths[i]]);
  }
  cout << res << " " << occ << endl;
  return;
}

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> lengths[i];
  Solves(N);
  return 0;
}