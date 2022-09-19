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

#define MAX 10
int T, N;
string num;

struct Node {
  int wordCount, prefixCount;
  Node* child[MAX];

  Node() {
    wordCount = 0, prefixCount = 0;
    for (int i = 0; i < MAX; i++) child[i] = NULL;
  }
};

void ins(Node* root, string key) {
  int idx = 0;
  Node* temp = root;
  for (int i = 0; i < (int)key.size(); i++) {
    idx = key[i] - '0';
    if (temp->child[idx] == NULL) temp->child[idx] = new Node();
    temp = temp->child[idx];
    temp->prefixCount++;
  }
  temp->wordCount++;
}

bool hasPrefix(Node* root) {
  for (int i = 0; i < MAX; i++) {
    if (root->child[i] != NULL) {
      if (root->wordCount) return true;
      if (hasPrefix(root->child[i])) return true;
    }
  }
  return false;
}

void del(Node* root) {
  for (int i = 0; i < MAX; i++) {
    if (root->child[i] != NULL) del(root->child[i]);
  }
  delete root;
}

void Solves() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N;
    Node* root = new Node();
    while (N--) {
      cin >> num;
      ins(root, num);
    }
    cout << "Case " << i << ": " << (hasPrefix(root) ? "NO" : "YES") << endl;
    del(root);
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}