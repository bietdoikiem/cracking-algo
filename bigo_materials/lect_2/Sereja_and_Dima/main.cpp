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

void Solves(vector<int>& cards, int N) {
  int l = 0, r = N - 1, s = 0, d = 0;
  bool flag = true;  // True for s | False for d
  while (l <= r) {
    if (cards[l] < cards[r]) {
      if (flag) {
        s += cards[r], r--, flag = false;
      } else {
        d += cards[r], r--, flag = true;
      }
    } else {
      if (flag) {
        s += cards[l], l++, flag = false;
      } else {
        d += cards[l], l++, flag = true;
      }
    }
  }
  cout << s << " " << d << endl;
  return;
}

int main() {
  int N;
  cin >> N;
  vector<int> cards(N);
  for (int i = 0; i < N; i++) scanf("%d", &cards[i]);
  Solves(cards, N);
  return 0;
}