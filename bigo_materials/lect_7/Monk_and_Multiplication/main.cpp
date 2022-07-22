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

ll N, A[100000], tmp, curProd;
priority_queue<ll, vector<ll>, less<ll>> pq;
stack<ll> st;

void Solves() {
  for (int i = 0; i < N; i++) {
    pq.push(A[i]);
    if (i < 2) {
      cout << "-1" << endl;
    } else {
      curProd = 1;
      // Peek top 3 elements
      for (int i = 0; i < 3; i++) {
        tmp = pq.top();
        curProd *= tmp;
        st.push(tmp);
        pq.pop();
      }
      cout << curProd << endl;
      // Add back top 3 elements from stack
      while (!st.empty()) {
        tmp = st.top();
        st.pop();
        pq.push(tmp);
      }
    }
  }
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  Solves();
  return 0;
}