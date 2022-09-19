#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

/***** SOLUTION BELOW HERE *****/

struct Contract {
  double a, b, d;
};

struct cpr {
  bool operator()(const Contract& x, const Contract& y) { return x.a < y.a; }
};

bool sortCpr(const Contract& x, const Contract& y) { return x.d < y.d; }

#define MAX 100005

ll t, N;
double a, b, d, x, S, curTime;
Contract contracts[MAX];

void Solves() {
  cin >> t;
  while (t--) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> a >> b >> d;
      contracts[i] = {a, b, d};
    }
    sort(contracts, contracts + N, sortCpr);  // Sort by closer deadline
    priority_queue<Contract, vector<Contract>, cpr> pq;
    S = 0.00, curTime = 0;
    for (int i = 0; i < N; i++) {
      curTime += contracts[i].b;
      pq.push(contracts[i]);
      while (curTime > contracts[i].d) {
        Contract top = pq.top();
        pq.pop();
        double reqTime = curTime - contracts[i].d;
        if (top.b > reqTime) {
          x = reqTime / top.a;
          top.b -= reqTime;
          pq.push(top);
          curTime = contracts[i].d;
        } else {
          x = top.b / top.a;
          curTime -= top.b;
          top.b = 0;
        }
        S += x;
      }
    }
    cout << fixed << setprecision(2) << S << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}