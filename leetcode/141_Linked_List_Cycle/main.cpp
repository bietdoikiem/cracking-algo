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
  ListNode(int x) : val(x), next(NULL){};
};

bool hasCycle(ListNode* head) {
  if (head == nullptr) return false;
  ListNode *turtle = head, *rabbit = head->next;
  while (rabbit != nullptr && turtle != nullptr) {
    if (rabbit == turtle) return true;
    turtle = turtle->next, rabbit = rabbit->next;
    if (rabbit != nullptr) rabbit = rabbit->next;
  }
  return false;
}

int main() { return 0; }