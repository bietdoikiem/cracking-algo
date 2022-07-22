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

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

/***** SOLUTION BELOW HERE *****/

int Q, q, v, tmp;
multiset<int, less<int>> mset;

void processQuery() {
  switch (q) {
    case 1:
      mset.insert(v);
      break;
    case 2:
      mset.erase(mset.find(v));
      break;
    case 3:
      cout << *(mset.begin()) << endl;
      break;
    default:
      break;
  }
}

void Solves() {
  for (int i = 0; i < Q; i++) {
    cin >> q;
    if (q == 1 || q == 2) cin >> v;
    processQuery();
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> Q;
  Solves();
  return 0;
}