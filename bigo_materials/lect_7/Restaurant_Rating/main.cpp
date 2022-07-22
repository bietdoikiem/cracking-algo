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

int N, n, O, X, rsize;
multiset<int> tp;
multiset<int, greater<int>> btm;  // Top 1/3 - Bottom 1/3

void Solves() {
  cin >> N;
  while (N--) {
    cin >> O;
    if (O == 1) {
      cin >> X;
      n++;
      btm.insert(X);
      if (n / 3 == 0) continue;
      if (n % 3 == 0) {
        int maxVal = *(btm.begin());
        tp.insert(maxVal);
        btm.erase(maxVal);
      } else {
        int minTpVal = *(tp.begin()), maxBtmVal = *(btm.begin());
        if (minTpVal < maxBtmVal) {
          tp.erase(minTpVal);
          btm.insert(minTpVal);
          tp.insert(maxBtmVal);
          btm.erase(maxBtmVal);
        }
      }
    } else {
      int tpSize = (int)tp.size();
      if (tpSize == 0) {
        cout << "No reviews yet" << endl;
      } else {
        cout << *(tp.begin()) << endl;
      }
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}
