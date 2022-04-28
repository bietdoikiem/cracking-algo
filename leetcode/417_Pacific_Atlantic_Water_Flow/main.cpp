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

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

bool isValid(vector<vector<bool>>& V, int R, int C, int x, int y) {
  if (x < 0 || y < 0 || x >= R || y >= C) return false;
  if (V[x][y]) return false;
  return true;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
  const int R = heights.size();
  const int C = heights[0].size();
  vector<vector<int>> ans;
  return ans;
}

int main() {
  vector<vector<int>> h1 = {{1, 2, 2, 3, 5},
                            {3, 2, 3, 4, 4},
                            {2, 4, 5, 3, 1},
                            {6, 7, 1, 4, 5},
                            {5, 1, 1, 2, 4}};
  cout << "ans1: " << pacificAtlantic(h1) << endl;
  vector<vector<int>> h2 = {{10, 10, 10}, {10, 1, 10}, {10, 10, 10}};
  cout << "ans2: " << pacificAtlantic(h2) << endl;
  return 0;
}