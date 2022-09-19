#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

/***** SOLUTION BELOW HERE *****/

#define MAX 26
int N;
string s;

struct Node {
  int wordCount, prefixCount;
  Node* next[MAX];

  Node() {
    wordCount = 0, prefixCount = 0;
    for (int i = 0; i < MAX; i++) next[i] = NULL;
  }

  bool ins(string key) {
    int idx = 0;
    Node* tmp = this;
    for (int i = 0; i < (int)key.size(); i++) {
      idx = key[i] - 'a';
      if (tmp->next[idx] == NULL) tmp->next[idx] = new Node();
      tmp = tmp->next[idx];
      if (tmp->wordCount) return false;
      tmp->prefixCount++;
    }
    if (tmp->prefixCount > 1) return false;
    tmp->wordCount++;
    return true;
  }
};

void Solves() {
  cin >> N;
  Node* root = new Node();
  bool flag = true;
  while (N--) {
    cin >> s;
    if (!(flag = root->ins(s))) break;
  }
  cout << (flag ? "non vulnerable" : "vulnerable") << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}