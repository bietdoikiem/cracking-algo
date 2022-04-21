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

void helper(vector<vector<int>>& ans, vector<int>& candidates, int& n,
            vector<int>& tmp, int st, int curSum, int target) {
  if (curSum == target) {
    ans.push_back(tmp);
    return;
  }
  int tmpSum;
  bool isExceeded = false;
  for (int i = st; i < n; i++) {
    if (isExceeded) break;
    tmpSum = curSum + candidates[i];
    if (tmpSum > target) {
      isExceeded = true;
      continue;
    }
    tmp.push_back(candidates[i]);
    helper(ans, candidates, n, tmp, i, tmpSum, target);
    tmp.pop_back();
  }
  return;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  int n = (int)candidates.size();
  vector<int> tmp;
  vector<vector<int>> ans;
  sort(candidates.begin(), candidates.end());
  helper(ans, candidates, n, tmp, 0, 0, target);
  return ans;
}

int main() {
  vector<int> c1 = {2, 3, 6, 7};
  int t1 = 7;
  cout << "ans1: " << combinationSum(c1, t1) << endl;
  vector<int> c2 = {2, 3, 5};
  int t2 = 8;
  cout << "ans2: " << combinationSum(c2, t2) << endl;
  vector<int> c3 = {2};
  int t3 = 1;
  cout << "ans3: " << combinationSum(c3, t3) << endl;
  return 0;
}