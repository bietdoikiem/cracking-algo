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

#define MAX 26

struct TrieNode {
  int wordCount, wordWeight, maxPrefixWeight;
  TrieNode* children[MAX];
};

TrieNode* newTrieNode() {
  TrieNode* node = new TrieNode;
  node->wordCount = 0;
  for (int i = 0; i < MAX; i++) {
    node->children[i] = NULL;
  }
  return node;
}

void addWord(TrieNode* root, string s, int w) {
  int ch = 0;
  TrieNode* temp = root;
  for (int i = 0; i < (int)s.size(); i++) {
    ch = s[i] - 'a';
    if (temp->children[ch] == NULL) {
      temp->children[ch] = newTrieNode();
    }
    temp = temp->children[ch];
  }
  temp->wordCount++;
  temp->wordWeight = max(temp->wordWeight, w);
}

bool findWord(TrieNode* root, string s) {
  int ch = 0;
  TrieNode* temp = root;
  for (int i = 0; i < (int)s.size(); i++) {
    ch = s[i] - 'a';
    if (temp->children[ch] == NULL) {
      return false;
    }
    temp = temp->children[ch];
  }
  return temp->wordCount > 0;
}

bool isEmpty(TrieNode* root) {
  for (int i = 0; i < MAX; i++) {
    if (root->children[i]) return false;
  }
  return true;
}

bool isWord(TrieNode* root) { return root->wordCount > 0; }

bool removeWord(TrieNode* root, string s, int level, int sLen) {
  if (!root) {
    return false;
  }
  if (level == sLen) {
    if (isWord(root)) {
      root->wordCount--;
      return true;
    }
    return false;
  }
  int ch = s[level] - 'a';
  bool flag = removeWord(root->children[ch], s, level + 1, sLen);
  if (flag && isWord(root->children[ch]) && isEmpty(root->children[ch])) {
    delete root->children[ch];
    root->children[ch] = NULL;
  }
  return flag;
}

string str;
int n, q, w;
int maxWeight = INT_MIN;

void autoComplete(TrieNode* root, string s) {
  if (isWord(root)) {
    maxWeight = max(root->wordWeight, maxWeight);
  }
  for (int i = 0; i < MAX; i++) {
    if (root->children[i]) {
      autoComplete(root->children[i], s + (char)(i + 'a'));
    }
  }
}

TrieNode* findPrefixNode(TrieNode* root, string prefix) {
  int ch = 0;
  TrieNode* temp = root;
  for (int i = 0; i < (int)prefix.size(); i++) {
    ch = prefix[i] - 'a';
    if (temp->children[ch] == NULL) {
      return NULL;
    }
    temp = temp->children[ch];
  }
  return temp;
}

void Solves() {
  cin >> n >> q;
  TrieNode* root = newTrieNode();
  while (n--) {
    cin >> str >> w;
    addWord(root, str, w);
  }
  while (q--) {
    string curStr, queryPrefix;
    maxWeight = INT_MIN;
    cin >> queryPrefix;
    curStr = queryPrefix;
    TrieNode* foundPrefix = findPrefixNode(root, queryPrefix);
    if (foundPrefix == NULL) {
      cout << "-1" << endl;
    } else {
      autoComplete(foundPrefix, curStr);
      cout << maxWeight << endl;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}