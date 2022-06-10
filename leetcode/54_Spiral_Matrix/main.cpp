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
int VISITED = 101;

void helper(vector<vector<int>>& matrix, vector<int>& ans, int rowStart,
            int rowEnd, int colStart, int colEnd) {
  // Handle invalid base case
  if (rowStart > rowEnd || colStart > colEnd) return;
  // Handle only-one center point left
  if (rowStart == rowEnd && colStart == colEnd) {
    ans.push_back(matrix[rowStart][colStart]);
    return;
  }
  // Traverse top cols
  for (int i = colStart; i < colEnd; i++) {
    if (matrix[rowStart][i] != VISITED) {
      ans.push_back(matrix[rowStart][i]);
      matrix[rowStart][i] = VISITED;
    }
  }
  // Traverse right-most rows
  for (int i = rowStart; i < rowEnd; i++) {
    if (matrix[i][colEnd] != VISITED) {
      ans.push_back(matrix[i][colEnd]);
      matrix[i][colEnd] = VISITED;
    }
  }
  // Traverse bottom cols
  for (int i = colEnd; i > colStart; i--) {
    if (matrix[rowEnd][i] != VISITED) {
      ans.push_back(matrix[rowEnd][i]);
      matrix[rowEnd][i] = VISITED;
    }
  }
  // Traverse left-most rows
  for (int i = rowEnd; i > rowStart; i--) {
    if (matrix[i][colStart] != VISITED) {
      ans.push_back(matrix[i][colStart]);
      matrix[i][colStart] = VISITED;
    }
  }
  // Recurse spiral order
  helper(matrix, ans, rowStart + 1, rowEnd - 1, colStart + 1, colEnd - 1);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  const int R = (int)matrix.size(), C = (int)matrix[0].size();
  vector<int> ans;
  helper(matrix, ans, 0, R - 1, 0, C - 1);
  return ans;
}

int main() {
  //
  return 0;
}