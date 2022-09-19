#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

/***** SOLUTION BELOW HERE *****/

#define MAX 2
#define MAX_N 1000
int N, L, arr[MAX_N];

vector<string> ans;
struct Node {
  int wordCount, prefixCount;
  Node* next[MAX];

  Node() {
    wordCount = 0, prefixCount = 0;
    for (int i = 0; i < MAX; i++) next[i] = NULL;
  }
};

bool constructable(Node* root, string& constructStr, int len, string cur) {
  root->prefixCount++;
  // cout << "cur.size: " << cur.size() << endl;
  if ((int)cur.size() == len) {
    if (root->prefixCount > 1) return false;
    root->wordCount++;
    constructStr = cur;
    // LOG(constructStr, cur, cur.size());
    return true;
  }
  for (int i = 0; i < MAX; i++) {
    if (root->next[i] == NULL) root->next[i] = new Node();
    if (root->next[i]->wordCount != 0) continue;
    if (constructable(root->next[i], constructStr, len,
                      cur + (char)(i + '0'))) {
      return true;
    }
  }
  return false;
}

void Solves() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  Node* root = new Node();
  bool flag = true;
  for (int i = 0; i < N; i++) {
    cin >> L;
    // cout << "L: " << L << endl;
    string cstr, cur;
    flag = constructable(root, cstr, L, cur);
    if (!flag) {
      flag = false;
      break;
    }
    ans.push_back(cstr);
  }
  if (flag) {
    cout << "YES" << endl;
    for (string& s : ans) cout << s << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}