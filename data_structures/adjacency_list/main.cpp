#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

void addEdge(vector<int> adj[], int src, int dest) {
  adj[src].push_back(dest);
  adj[dest].push_back(src);
}

void displayGraph(vector<int> adj[], int V) {
  for (int i = 0; i < V; i++) {
    cout << i << " -> ";
    for (auto e : adj[i]) {
      cout << e << " ";
    }
    cout << endl;
  }
}

int main() {
  //
  const int V = 4;
  vector<int> adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 3);
  displayGraph(adj, V);
  return 0;
}