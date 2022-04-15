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

void helper(vector<vector<int>>& ans, vector<int>& nums, int n, vector<int>& t,
            int st) {
  ans.push_back(t);
  for (int i = st; i < n; i++) {
    if (i > st && nums[i] == nums[i - 1]) {
      continue;
    }
    t.push_back(nums[i]);
    helper(ans, nums, n, t, i + 1);
    t.pop_back();
  }
  return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<int> t;
  vector<vector<int>> ans;
  helper(ans, nums, nums.size(), t, 0);
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 2};
  cout << subsetsWithDup(nums) << endl;
  return 0;
}