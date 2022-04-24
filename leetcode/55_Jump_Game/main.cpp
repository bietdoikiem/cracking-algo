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

bool dp[10001];

// NOTE: Not as efficient as greedy method
bool canJump(vector<int>& nums) {
  int n = (int)nums.size();
  dp[0] = true, dp[1] = n >= 2 && nums[0] == 0 ? false : true;
  for (int i = 2; i < n + 1; i++) {
    if (nums[i - 2] == 0) {
      for (int j = i - 1; j > 0; j--) {
        if (dp[j] == true && (i - 1) - (j - 1) <= nums[j - 1]) {
          dp[i] = true;
        }
      }
    } else {
      dp[i] = dp[i - 1];
    }
  }
  return dp[n];
}

bool canJumpGreedy(vector<int>& nums) {
  int n = (int)nums.size();
  int dest = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (nums[i] + i >= dest) {
      dest = i;
    }
  }
  return dest == 0;
}

int main() {
  cout << boolalpha;
  vector<int> n1 = {2, 3, 1, 1, 4};
  cout << "ans1: " << canJump(n1) << endl;
  memset(dp, 0, sizeof(dp));  // Reset DP cache
  vector<int> n2 = {3, 2, 1, 0, 4};
  cout << "ans2: " << canJump(n2) << endl;
  memset(dp, 0, sizeof(dp));  // Reset DP Cache
  return 0;
}