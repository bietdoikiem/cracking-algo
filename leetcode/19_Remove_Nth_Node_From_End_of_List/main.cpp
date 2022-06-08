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

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Solution using stack: O(n) time - O(n) space -> Not really optimal!
ListNode* removeNthFromEnd(ListNode* head, int n) {
  stack<ListNode*> s;
  ListNode *cur = head, *next = nullptr;
  while (cur != nullptr) s.push(cur), cur = cur->next;
  int pos = 1;
  while (!s.empty()) {
    cur = s.top(), s.pop();
    cur->next = next;
    if (pos != n) next = cur;
    if (pos == n) cur = next;
    pos++;
  }
  return cur;
}

// Solution using 2 passes: O(n) time - O(1) space
ListNode* removeNthFromEndTwoPasses(ListNode* head, int n) {
  int L = 0;
  ListNode *d = new ListNode(0), *cur = head;
  d->next = head;
  while (cur != nullptr) cur = cur->next, L++;
  L -= n, cur = d;
  while (L > 0) cur = cur->next, L--;
  cur->next = cur->next->next;
  return d->next;
}

int main() {
  // TODO: Solve the problem!
  return 0;
}