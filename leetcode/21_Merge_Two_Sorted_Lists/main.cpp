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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *h = new ListNode, *cur = h;
  if (list1 == nullptr || list2 == nullptr)
    return list1 == nullptr ? list2 : list1;
  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val < list2->val) {
      cur->next = list1, list1 = list1->next;
    } else {
      cur->next = list2, list2 = list2->next;
    }
    cur = cur->next;
  }
  // Merge remaining elements
  if (list1 != nullptr) cur->next = list1;
  if (list2 != nullptr) cur->next = list2;
  return h->next;
}

ListNode* mergeTwoListsRecursive(ListNode* list1, ListNode* list2) {
  if (list1 == nullptr || list2 == nullptr) {
    return list1 == nullptr ? list2 : list1;
  }
  if (list1->val <= list2->val) {
    list1->next = mergeTwoListsRecursive(list1->next, list2);
    return list1;
  } else {
    list2->next = mergeTwoListsRecursive(list1, list2->next);
    return list2;
  }
}

int main() { return 0; }