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

void addEdge(vector<int> adj[], int s, int d) { adj[s].push_back(d); }

void displayGraph(vector<int> adj[], int V) {
  for (int i = 0; i < V; i++) {
    cout << i << " -> ";
    for (auto e : adj[i]) {
      cout << e << " ";
    }
    cout << endl;
  }
}

bool dfs(vector<int> adj[], bool V[], int u, int o) {
  V[u] = true;
  for (int e : adj[u]) {
    if (e == o) return false;
    if (!V[e]) {
      if (!dfs(adj, V, e, o)) return false;
    };
  }
  return true;
}

// NOTE: Inefficient way to exhaustively search in all vertices to detect cycle
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> adj[numCourses];
  bool V[numCourses];
  memset(V, 0, sizeof(V));
  for (auto& c : prerequisites) addEdge(adj, c[1], c[0]);

  for (int i = 0; i < numCourses; i++) {
    if (!dfs(adj, V, i, i)) return false;
    memset(V, 0, sizeof(V));  // Reset visited node for each traversed vertex
  }
  return true;
}

void dfsTopo(vector<int> adj[], bool V[], stack<int>& s, int u) {
  V[u] = true;
  for (auto& e : adj[u]) {
    if (!V[e]) dfsTopo(adj, V, s, e);
  }
  s.push(u);
  return;
}

bool canFinishTopo(int numCourses, vector<vector<int>>& prerequisites) {
  const int N = numCourses;
  vector<int> adj[N];
  // Build directed graph from prerequisites
  for (auto& p : prerequisites) {
    if (p[1] == p[0]) return false;  // Early detection of cycle
    addEdge(adj, p[1], p[0]);
  };
  // Boolean array to keep track of visited vertices
  bool V[N];
  memset(V, false, sizeof(V));  // Initialize visited array with 'false'
  // Stack to store DFS Topological sort order
  stack<int> s;
  for (int i = 0; i < N; i++) {
    if (!V[i]) dfsTopo(adj, V, s, i);
  }
  // HashMap to store insert position of Topological sort
  unordered_map<int, int> posMap;
  int insIdx = 0;
  while (!s.empty()) {
    posMap[s.top()] = insIdx;
    s.pop();
    insIdx++;
  }
  // Iterate parent vertices and their children
  for (int i = 0; i < N; i++) {
    for (auto& e : adj[i]) {
      if (posMap[i] > posMap[e]) return false;
    }
  }
  return true;
}

bool dfsAcyclic(vector<int> adj[], char color[], int u) {
  color[u] = 1;
  for (auto& e : adj[u]) {
    if (color[e] == 0) {
      if (!dfsAcyclic(adj, color, e)) return false;
    }
    if (color[e] == 1) return false;
  }
  color[u] = 2;
  return true;
}

bool canFinishAcyclic(int numCourses, vector<vector<int>>& prerequisites) {
  const int N = numCourses;
  vector<int> adj[N];
  char color[N];
  memset(color, 0, sizeof(color));
  // Build directed graph
  for (auto& p : prerequisites) addEdge(adj, p[1], p[0]);
  // Traverse all vertices to detect cycle
  for (int i = 0; i < N; i++) {
    if (color[i] == 0 && !dfsAcyclic(adj, color, i)) return false;
  }
  return true;
}

int main() {
  cout << boolalpha;
  int n1 = 2;
  vector<vector<int>> p1 = {{1, 0}};
  cout << "ans1: " << canFinish(n1, p1) << endl;  // true
  int n2 = 2;
  vector<vector<int>> p2 = {{1, 0}, {0, 1}};  // false
  cout << "ans2: " << canFinish(n2, p2) << endl;
  int n3 = 3;
  vector<vector<int>> p3 = {{1, 0}, {2, 1}, {0, 2}};  // false
  cout << "ans3: " << canFinish(n3, p3) << endl;
  int n4 = 4;
  vector<vector<int>> p4 = {{2, 0}, {1, 0}, {3, 1}, {3, 2}, {1, 3}};  // false
  cout << "ans4: " << canFinish(n4, p4) << endl;
  int n5 = 4;
  vector<vector<int>> p5 = {{1, 0}, {2, 1}, {3, 2}, {1, 3}};  // false
  cout << "ans5: " << canFinish(n5, p5) << endl;
  int n6 = 5;
  vector<vector<int>> p6 = {{1, 4}, {2, 4}, {3, 1}, {3, 2}};  // true
  cout << "ans6: " << canFinish(n6, p6) << endl;
  int n7 = 3;
  vector<vector<int>> p7 = {{0, 1}, {0, 2}, {1, 2}, {2, 1}};  // false
  cout << "ans7: " << canFinish(n7, p7) << endl;
  return 0;
}