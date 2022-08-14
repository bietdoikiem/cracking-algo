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

#define MAX_DNA 4

int T, N, maxSub;
string s;
char dna[4] = {'A', 'C', 'G', 'T'};

int mapIndex(char c) {
  switch (c) {
    case 'A':
      return 0;
    case 'C':
      return 1;
    case 'G':
      return 2;
    case 'T':
      return 3;
    default:
      break;
  }
  return -1;
}

struct TrieNode {
  int wordCount, prefixCount;
  TrieNode* child[MAX_DNA];
};

TrieNode* newTrieNode() {
  TrieNode* node = new TrieNode;
  node->wordCount = 0, node->prefixCount = 0;
  for (int i = 0; i < MAX_DNA; i++) {
    node->child[i] = NULL;
  }
  return node;
}

void insert(TrieNode* root, string key) {
  int ch = 0;
  TrieNode* temp = root;
  for (int i = 0; i < (int)key.size(); i++) {
    ch = mapIndex(key[i]);
    if (temp->child[ch] == NULL) {
      temp->child[ch] = newTrieNode();
    }
    temp = temp->child[ch];
    temp->prefixCount++;
  }
  temp->wordCount++;
}

void findMax(TrieNode* root, string cur) {
  if (root->prefixCount > 0) {
    maxSub = max(maxSub, root->prefixCount * (int)cur.size());
  }
  for (int i = 0; i < MAX_DNA; i++) {
    if (root->child[i]) {
      findMax(root->child[i], cur + dna[i]);
    }
  }
}

void Solves() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  for (int i = 1; i <= T; i++) {
    TrieNode* root = newTrieNode();
    maxSub = INT_MIN;
    cin >> N;
    while (N--) {
      cin >> s;
      insert(root, s);
    }
    string cur;
    findMax(root, cur);
    cout << "Case " << i << ": " << maxSub << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}