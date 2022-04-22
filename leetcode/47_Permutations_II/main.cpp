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

void helper(vector<vector<int>>& ans, vector<int>& nums, int n,
            vector<int>& tmp, vector<bool>& used) {
  if ((int)tmp.size() == n) {
    ans.push_back(tmp);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
    tmp.push_back(nums[i]);
    used[i] = true;
    helper(ans, nums, n, tmp, used);
    used[i] = false;
    tmp.pop_back();
  }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<int> tmp;
  vector<bool> used((int)nums.size(), false);
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  helper(ans, nums, nums.size(), tmp, used);
  return ans;
}

int main() {
  vector<int> nums1 = {3, 3, 0, 3};
  cout << "Answer1 is: " << permuteUnique(nums1) << endl;
  vector<int> nums2 = {1, 2, 2};
  cout << "Answer2 is: " << permuteUnique(nums2) << endl;
  vector<int> nums3 = {-1, 2, -1, 2};
  cout << "Answer3 is: " << permuteUnique(nums3) << endl;
  return 0;
}