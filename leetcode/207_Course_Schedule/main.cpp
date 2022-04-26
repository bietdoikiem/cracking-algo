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

void dfs(vector<int> adj[], bool V[], int c, int o, bool* hasCycle) {
  V[c] = true;
  for (int e : adj[c]) {
    if (e == o) {
      *hasCycle = true;
      return;
    };
    if (!V[e]) dfs(adj, V, e, o, hasCycle);
  }
  return;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
  vector<int> adj[numCourses];
  bool V[numCourses];
  memset(V, 0, sizeof(V));
  bool hasCycle = false;
  for (auto& c : prerequisites) addEdge(adj, c[1], c[0]);

  for (int i = 0; i < numCourses; i++) {
    dfs(adj, V, i, i, &hasCycle);
    memset(V, 0, sizeof(V));  // Reset visited node for each traversed vertex
    if (hasCycle) return false;
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
  cout << "ans6: " << canFinish(n7, p7) << endl;
  return 0;
}