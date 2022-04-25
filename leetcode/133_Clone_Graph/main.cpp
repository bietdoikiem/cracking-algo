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
  for (auto& y : x) os << y << " ";
  return os << "}";
}

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto& y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

void dfs(unordered_map<Node*, Node*>& V, Node* nn, Node* on) {
  vector<Node*> nb;
  V[on] = nn;
  for (auto u : on->neighbors) {
    if (V.find(u) == V.end()) {
      dfs(V, new Node(u->val), u);
    }
    nb.push_back(V[u]);
  }
  nn->neighbors = nb;
}

Node* cloneGraph(Node* node) {
  if (node == nullptr) return node;
  unordered_map<Node*, Node*> V;
  Node* nn = new Node(node->val);
  dfs(V, nn, node);
  return nn;
}

int main() { return 0; }