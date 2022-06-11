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
bool isValid(vector<vector<char>>& board, int R, int C, int N, int x, int y,
             int n) {
  return x >= 0 && y >= 0 && x < R && y < C && n < N && board[x][y] != '\0';
}

bool dfs(vector<vector<char>>& board, string& word, int R, int C, int N, int x,
         int y, int c) {
  if (board[x][y] == word[c] && c == N - 1) return true;
  char tmp = board[x][y];
  board[x][y] = '/0';  // Mark as visited
  for (int i = 0; i < 4; i++) {
    int nx = x + dX[i], ny = y + dY[i], nc = c + 1;
    if (isValid(board, R, C, N, nx, ny, nc) && board[nx][ny] == word[nc] &&
        dfs(board, word, R, C, N, nx, ny, nc)) {
      return true;
    }
  }
  board[x][y] = tmp;  // Backtracking
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  int R = (int)board.size(), C = (int)board[0].size(), N = (int)word.size();
  // Prune if word does not fit the board
  if (N > R * C) return false;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] == word[0] && dfs(board, word, R, C, N, i, j, 0)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  // TODO: Solve the problem!
  return 0;
}