#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, type, x;
  stack<int> s;
  queue<int> q;
  priority_queue<int> pq;
  bool isStack, isQueue, isPQ;

  while (cin >> n) {
    while (!s.empty()) s.pop();
    while (!q.empty()) q.pop();
    while (!pq.empty()) pq.pop();
    isStack = isQueue = isPQ = true;

    for (int i = 0; i < n; i++) {
      cin >> type >> x;

      if (type == 1) {
        s.push(x);
        q.push(x);
        pq.push(x);
      } else {
        if (s.empty()) {
          isStack = isQueue = isPQ = false;
          continue;
        }

        if (s.top() != x) {
          isStack = false;
        }
        if (q.front() != x) {
          isQueue = false;
        }
        if (pq.top() != x) {
          isPQ = false;
        }

        s.pop();
        q.pop();
        pq.pop();
      }
    }

    if (isStack + isQueue + isPQ == 0) {
      cout << "impossible" << endl;
    } else if (isStack + isQueue + isPQ > 1) {
      cout << "not sure" << endl;
    } else if (isStack) {
      cout << "stack" << endl;
    } else if (isQueue) {
      cout << "queue" << endl;
    } else {
      cout << "priority queue" << endl;
    }
  }
  return 0;
}