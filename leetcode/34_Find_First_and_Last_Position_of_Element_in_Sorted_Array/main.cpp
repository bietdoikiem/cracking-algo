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

void helper(vector<int>& nums, int n, vector<int>& ans, int target, int ml,
            int mr) {
  if (ml < 0 || mr >= n) {
    return;
  }
  int l = ml;
  int r = mr;
  int m;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (nums[m] < target) {
      l = m + 1;
    } else if (nums[m] > target) {
      r = m - 1;
    } else {
      if (ans[0] == -1 && ans[1] == -1) {
        ans[0] = m;
        ans[1] = m;
        continue;
      }
      ans[0] = min(ans[0], m);
      ans[1] = max(ans[1], m);
      helper(nums, n, ans, target, l, m - 1);
      helper(nums, n, ans, target, m + 1, r);
      break;
    }
  }
}

vector<int> searchRange(vector<int>& nums, int target) {
  int n = (int)nums.size();
  vector<int> ans(2, -1);
  if (n == 0) {
    return ans;
  }
  helper(nums, n, ans, target, 0, n - 1);
  return ans;
}

int main() {
  vector<int> nums1 = {5, 7, 7, 8, 8, 10};
  int t1 = 8;
  cout << "ans1: " << searchRange(nums1, t1) << endl;
  vector<int> nums2 = {1};
  int t2 = 1;
  cout << "ans2: " << searchRange(nums2, t2) << endl;
  return 0;
}