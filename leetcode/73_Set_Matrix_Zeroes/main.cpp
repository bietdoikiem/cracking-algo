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

// O(m*n) Time - O(m+n) Space
void setZeroes(vector<vector<int>>& matrix) {
  const int R = (int)matrix.size(), C = (int)matrix[0].size();
  unordered_set<int> sr, sc;
  // Append rows, columns to be set zeros
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (matrix[i][j] == 0) sr.insert(i), sc.insert(j);
    }
  }
  // Zero-ify process
  for (const auto& r : sr) {
    for (int j = 0; j < C; j++) matrix[r][j] = 0;
  }
  for (const auto& c : sc) {
    for (int i = 0; i < R; i++) matrix[i][c] = 0;
  }
}

// O(m*n) Time - O(1) Space
void setZeroesSpaceOptimized(vector<vector<int>>& matrix) {
  const int R = (int)matrix.size(), C = (int)matrix[0].size();
  bool isCol = false;
  // Set Flags
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (matrix[i][j] == 0) {
        if (i == 0) {
          isCol = true;
          continue;
        }
        matrix[i][0] = 0, matrix[0][j] = 0;
      }
    };
  }
  // Zero-ify
  for (int i = 1; i < R; i++) {
    for (int j = 1; j < C; j++) {
      if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
    }
  }
  // Zero-ify row
  if (matrix[0][0] == 0) {
    for (int i = 0; i < R; i++) matrix[i][0] = 0;
  }
  // Zero-ify col
  if (isCol) {
    for (int j = 0; j < C; j++) matrix[0][j] = 0;
  }
}

int main() {
  vector<vector<int>> m1 = {
      {1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
  return 0;
}