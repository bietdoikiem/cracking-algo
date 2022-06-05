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

ListNode* mergeKLists(vector<ListNode*>& lists) {
  auto comparator = [](ListNode*& a, ListNode*& b) { return a->val > b->val; };
  priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> pq(
      comparator);
  for (auto& l : lists)
    if (l) pq.push(l);
  ListNode *n = new ListNode(0), *h = n;
  while (!pq.empty()) {
    ListNode* m = pq.top();
    pq.pop();
    n->next = new ListNode(m->val);
    n = n->next;
    if (m->next) pq.push(m->next);
  }
  return h->next;
}

int main() { return 0; }