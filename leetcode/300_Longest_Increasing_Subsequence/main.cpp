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

int dp[2501];

int dp2[2500];

int max(int x, int y) { return x > y ? x : y; }

int helper(vector<int>& nums, int cur, int prev) {
  if (cur >= nums.size()) {
    return 0;
  }
  if (dp[prev + 1] != 0) {
    return dp[prev + 1];
  }
  if (prev == -1 || nums[cur] > nums[prev]) {
    dp[prev + 1] =
        max(1 + helper(nums, cur + 1, cur), helper(nums, cur + 1, prev));
    return dp[prev + 1];
  }
  dp[prev + 1] = helper(nums, cur + 1, prev);
  return dp[prev + 1];
}

// lengthOfLIS (Top-Down memoization approach)
int lengthOfLIS(vector<int>& nums) {
  int ans = helper(nums, 0, -1);
  return ans;
}

// lengthOfLISBottomUp (Bottom-Up Dynamic approach)
int lengthOfLISBottomUp(vector<int>& nums) {
  size_t n = nums.size();
  int ans = 1;
  for (size_t i = n - 1; i < n; i--) {
    dp2[i] = 1;
    for (size_t j = n - 1; j < n && j > i; j--) {
      if (nums[i] < nums[j]) {
        dp2[i] = max(dp2[i], 1 + dp2[j]);
        ans = max(ans, dp2[i]);
      }
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << "Longest subsequence length is: " << lengthOfLISBottomUp(nums)
       << endl;
  nums = {0, 1, 0, 3, 2, 3};
  memset(dp2, 0, sizeof(dp2));  // Reset DP cache
  cout << "Longest subsequence length is: " << lengthOfLISBottomUp(nums)
       << endl;
  nums = {7, 7, 7, 7, 7, 7, 7};
  memset(dp2, 0, sizeof(dp2));
  cout << "Longest subsequence length is: " << lengthOfLISBottomUp(nums)
       << endl;
  nums = {0};
  memset(dp2, 0, sizeof(dp2));
  cout << "Longest subsequence length is: " << lengthOfLISBottomUp(nums)
       << endl;
  return 0;
}