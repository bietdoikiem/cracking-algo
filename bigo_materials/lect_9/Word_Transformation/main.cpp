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

string A, B;
int T;
map<string, vector<string>> adj;

bool isValidDiff(string cur, string tmp) {
  int n = (int)cur.size(), m = (int)tmp.size();
  if (n != m) return false;
  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (cur[i] != tmp[i]) diff++;
  }
  return diff <= 1;
}

int bfs() {
  queue<string> q;
  map<string, int> dist;
  dist[A] = 0;
  q.push(A);
  while (!q.empty()) {
    string u = q.front();
    q.pop();
    if (u == B) break;
    for (auto& v : adj[u]) {
      if (dist.find(v) == dist.end()) dist[v] = dist[u] + 1, q.push(v);
    }
  }
  return dist[B];
}

void Solves() {
  string str;
  cin >> T;
  getline(cin, str);  // Skip blank line
  while (T--) {
    vector<string> dict;
    while (getline(cin, str), str != "*") {
      dict.push_back(str);
    }
    // Build graph of valid diff words
    int n = (int)dict.size();
    adj.clear();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isValidDiff(dict[i], dict[j])) {
          adj[dict[i]].push_back(dict[j]);
          adj[dict[j]].push_back(dict[i]);
        }
      }
    }
    while (getline(cin, str) && !str.empty()) {  // Transform words
      stringstream ss(str);
      ss >> A >> B;
      cout << A << " " << B << " " << bfs() << endl;
    }
    if (T) cout << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}