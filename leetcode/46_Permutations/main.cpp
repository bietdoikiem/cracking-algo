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
            vector<int>& t) {
  if ((int)t.size() == n) {
    ans.push_back(t);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (find(t.begin(), t.end(), nums[i]) != t.end()) continue;
    t.push_back(nums[i]);
    helper(ans, nums, n, t);
    t.pop_back();
  }
  return;
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<int> t;
  vector<vector<int>> ans;
  helper(ans, nums, nums.size(), t);
  return ans;
}

void swap(vector<int>& arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void helperSwap(vector<vector<int>>& ans, vector<int>& nums, int n,
                vector<int>& tmp, int st) {  //
  if ((int)tmp.size() == n) {
    ans.push_back(tmp);
    return;
  }
  for (int i = st; i < n; i++) {
    tmp.push_back(nums[i]);
    swap(nums, st, i);
    helperSwap(ans, nums, n, tmp, st + 1);
    swap(nums, st, i);
    tmp.pop_back();
  }
}
vector<vector<int>> permuteSwap(vector<int>& nums) {
  vector<int> tmp;
  vector<vector<int>> ans;
  helperSwap(ans, nums, nums.size(), tmp, 0);
  return ans;
}

int main() {
  vector<int> nums = {1, 2, 3};
  cout << "Answer is: " << permute(nums) << endl;
  cout << "Answer (Swap method) is: " << permuteSwap(nums) << endl;
  return 0;
}