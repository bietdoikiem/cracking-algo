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

int orangesRotting(vector<vector<int>>& grid) {
  const int R = grid.size();
  const int C = grid[0].size();
  queue<pair<int, int>> q;
  int fresh = 0;
  int ans = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (grid[i][j] == 2) {
        q.push({i, j});
      } else if (grid[i][j] == 1) {
        fresh++;
      }
    }
  }
  while (!q.empty()) {
    int n = (int)q.size();
    for (int i = 0; i < n; i++) {
      pair<int, int> cur = q.front();
      int x = cur.first;
      int y = cur.second;
      for (int j = 0; j < 4; j++) {
        int nx = x + dX[j];
        int ny = y + dY[j];
        if ((nx >= 0 && ny >= 0 && nx < R && ny < C) && grid[nx][ny] != 0 &&
            grid[nx][ny] != 2) {
          q.push({nx, ny});
          grid[nx][ny] = 2;
          fresh--;
        }
      }
      q.pop();
    }
    ans++;  // A minute passed
  }
  ans = ans != 0 ? ans - 1 : 0;  // Remove the last minute as no more rotten
                                 // oranges can be affected
  if (fresh != 0) return -1;     // Check remaining fresh
  return ans;
}

int main() {
  vector<vector<int>> g1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  cout << "ans1: " << orangesRotting(g1) << endl;
  vector<vector<int>> g2 = {{0, 2}};
  cout << "ans2: " << orangesRotting(g2) << endl;
  vector<vector<int>> g3 = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
  cout << "ans3: " << orangesRotting(g3) << endl;
  vector<vector<int>> g4 = {{0}};
  cout << "ans4: " << orangesRotting(g4) << endl;
  return 0;
}