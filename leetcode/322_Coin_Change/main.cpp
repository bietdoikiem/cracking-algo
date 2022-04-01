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

int dp[10001];

int min(int x, int y) { return x < y ? x : y; }

int helper(vector<int>& coins, int amountLeft) {
  if (amountLeft < 0) {
    return INT_MAX;
  }
  if (dp[amountLeft] != 0) {
    return dp[amountLeft];
  }
  int minSteps = INT_MAX;
  for (auto& c : coins) {
    minSteps = min(minSteps, helper(coins, amountLeft - c));
  }
  dp[amountLeft] = minSteps;
  if (minSteps == INT_MAX) {
    return dp[amountLeft];
  }
  dp[amountLeft] += 1;
  return dp[amountLeft];
}

int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  for (auto& c : coins) {
    dp[c] = 1;
  }
  int ans;
  ans = helper(coins, amount);
  for (size_t i = 0; i < amount; i++)
    if (ans == INT_MAX) {
      return -1;
    }
  return ans;
}

int coinChangeBU(vector<int>& coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  fill_n(dp, size(dp), INT_MAX);
  for (auto& c : coins) {
    if (c <= 10001) {
      dp[c] = 1;
    }
  }
  for (int a = 1; a < amount + 1; a++) {
    for (auto& c : coins) {
      if (a - c > 0) {
        if (dp[a - c] != INT_MAX) {
          dp[a] = min(dp[a], 1 + dp[a - c]);
        }
      }
    }
  }
  if (dp[amount] != INT_MAX) {
    return dp[amount];
  }
  return -1;
}

int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  cout << "answer: " << coinChangeBU(coins, amount) << endl;
  coins = {2};
  amount = 3;
  cout << "answer: " << coinChangeBU(coins, amount) << endl;
  return 0;
}