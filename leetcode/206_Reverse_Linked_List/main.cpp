#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// printList prints the list of node values in the singly linked list
void printList(ListNode* head) {
  ListNode* cur = head;
  cout << "{ ";
  while (cur != nullptr) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << "}" << endl;
}

ListNode* reverseList(ListNode* head) {
  if (head != nullptr) {
    return head;
  }
  if (head->next == nullptr) {
    return head;
  }
  // In-place reverse the linked list
  ListNode* prev = nullptr;
  ListNode* cur = head;
  ListNode* next = nullptr;
  while (cur != nullptr) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

void Solve() {
  ListNode* head = new ListNode(1);
  ListNode* e2 = new ListNode(2);
  ListNode* e3 = new ListNode(3);
  ListNode* e4 = new ListNode(4);
  ListNode* e5 = new ListNode(5);
  // Link the nodes
  head->next = e2;
  e2->next = e3;
  e3->next = e4;
  e4->next = e5;
  ListNode* ans = reverseList(head);
  printList(ans);
}

int main() {
  Solve();
  return 0;
}