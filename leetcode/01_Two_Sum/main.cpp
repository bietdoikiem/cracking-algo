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

vector<int> twoSum(vector<int>& nums, int target) {
  int n = nums.size();
  int diff = 0;
  unordered_map<int, int> diffMap;
  for (int i = 0; i < n; i++) {
    diff = target - nums[i];
    // Check for not exist
    if (diffMap.find(diff) == diffMap.end()) {
      diffMap[nums[i]] = i;
      continue;
    }
    // If exists
    return {diffMap[diff], i};
  }
  return {};
}

int main() {
  // Random input
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  cout << twoSum(nums, target) << endl;
  return 0;
}