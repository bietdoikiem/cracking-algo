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

// Most intuitive solution (Transpose & Reflect)
void rotate(vector<vector<int>>& matrix) {
  int n = (int)matrix.size();
  // Transpose
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  // Reflect
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      swap(matrix[i][j], matrix[i][n - 1 - j]);
    }
  }
}

// Not quite optimal solution regarding space!
int tmp[19];  // Temporal values on rotation

void helper(vector<vector<int>>& matrix, int s, int e) {
  if (s >= e) return;
  // Rotate corners from top -> right -> bottom -> left
  int topLeft = matrix[s][s], topRight = matrix[s][e];
  int bottomLeft = matrix[e][s], bottomRight = matrix[e][e];
  matrix[s][e] = topLeft, matrix[e][e] = topRight;
  matrix[e][s] = bottomRight, matrix[s][s] = bottomLeft;
  // Rotate top to right
  for (int i = s + 1; i < e; i++)
    tmp[i] = matrix[i][e], matrix[i][e] = matrix[s][i];
  // Rotate right to bottom (reverse temp)
  for (int i = e - 1; i > s; i--) swap(tmp[e - i + s], matrix[e][i]);
  // Rotate bottom to left (reverse temp)
  for (int i = e - 1; i > s; i--) swap(tmp[e - i + s], matrix[i][s]);
  // Rotate left to top
  for (int i = s + 1; i < e; i++) matrix[s][i] = tmp[i];
  helper(matrix, s + 1, e - 1);
}

void rotateExtraSpace(vector<vector<int>>& matrix) {
  helper(matrix, 0, matrix.size() - 1);
}

int main() { return 0; }
