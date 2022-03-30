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

vector<vector<int>> threeSum(vector<int>& nums) {
  int n = nums.size();
  if (n < 3) {
    return {};
  }
  int l = 0;
  int r = 0;
  int target = 0;
  int curSum = 0;
  sort(nums.begin(), nums.end());
  vector<int> triplet = {0, 0, 0};
  vector<vector<int>> ans = {};
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      if (nums[i] == nums[i - 1]) {
        continue;
      }
    }
    l = i + 1;
    r = n - 1;
    while (l < r) {
      if (l > i + 1) {
        if (nums[l] == nums[l - 1]) {
          l++;
          continue;
        }
      }
      if (r < n - 1) {
        if (nums[r] == nums[r + 1]) {
          r--;
          continue;
        }
      }
      curSum = nums[l] + nums[r] + nums[i];
      if (curSum > 0) {
        r--;
      } else if (curSum < 0) {
        l++;
      } else {
        triplet[0] = nums[i];
        triplet[1] = nums[l];
        triplet[2] = nums[r];
        ans.push_back(triplet);
        r--;
        l++;
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  cout << threeSum(nums) << endl;
  return 0;
}