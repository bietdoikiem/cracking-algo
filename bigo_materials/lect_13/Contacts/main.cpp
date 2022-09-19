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

#define MAX_ALPHA 26
int n;
string name, partial, op, s;

struct Node {
  int wordCount, prefixCount;
  Node* child[MAX_ALPHA];

  Node() {
    wordCount = 0, prefixCount = 0;
    for (int i = 0; i < MAX_ALPHA; i++) child[i] = NULL;
  }

  void ins(string key) {
    int idx = 0;
    Node* tmp = this;
    for (int i = 0; i < (int)key.size(); i++) {
      idx = key[i] - 'a';
      if (tmp->child[idx] == NULL) {
        tmp->child[idx] = new Node();
      }
      tmp = tmp->child[idx];
      tmp->prefixCount++;
    }
    tmp->wordCount++;
  }

  int findPrefixCount(string key) {
    int idx = 0;
    Node* tmp = this;
    for (int i = 0; i < (int)key.size(); i++) {
      idx = key[i] - 'a';
      if (tmp->child[idx] == NULL) {
        return 0;
      }
      tmp = tmp->child[idx];
    }
    return tmp->prefixCount;
  }
};

void Solves() {
  cin >> n;
  Node* root = new Node();
  while (n--) {
    cin >> op >> s;
    if (op == "add") {
      root->ins(s);
    } else if (op == "find") {
      cout << root->findPrefixCount(s) << endl;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}