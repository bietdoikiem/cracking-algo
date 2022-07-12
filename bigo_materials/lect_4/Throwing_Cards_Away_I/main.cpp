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

deque<int> dq;
vector<int> dCards;

void Solves() {
  while (dq.size() > 1) {
    dCards.push_back(dq.front());
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }
  return;
}

int main() {
  int n;
  while (cin >> n && n) {
    dCards.clear(), dq.clear();
    for (int i = 1; i <= n; i++) dq.push_back(i);
    Solves();
    if ((int)dCards.size() == 0) {
      cout << "Discarded cards:" << endl;
    } else {
      cout << "Discarded cards: ";
    }
    for (int i = 0; i < (int)dCards.size(); i++) {
      if (i == (int)dCards.size() - 1) {
        cout << dCards[i] << endl;
      } else {
        cout << dCards[i] << ", ";
      }
    }
    cout << "Remaining card: " << dq.front() << endl;
  }
  return 0;
}