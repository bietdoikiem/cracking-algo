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
  for (auto y : x) os << y << " ";
  return os << "}";
}

template <class T, size_t SIZE>
void printArr(T const (&x)[SIZE]) {
  cout << "{ ";
  for (auto y : x) cout << y << " ";
  cout << "}" << endl;
}

template <class... Args>
auto& log(const Args&... args) {
  return ((cerr << " " << args), ...) << '\n';
}

#define LOG(...)                     \
  cerr << "[ " #__VA_ARGS__ " ] = "; \
  log(__VA_ARGS__) << '\n'

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

/***** SOLUTION BELOW HERE *****/

int shipWithinDays(vector<int>& weights, int days) {
  int n = (int)weights.size();
  int l = *max_element(weights.begin(), weights.end());
  int r = accumulate(weights.begin(), weights.end(), 0);
  int ans = 0;
  while (l <= r) {
    int m = l + (r - l) / 2;
    int curSum = 0, curDays = 1;
    for (int i = 0; i < n; i++) {
      int rPkgs = n - i;           // Remaining packages
      int rDays = days - curDays;  // Remaining days
      // Early stop if the remaining packages == remaining days
      if (rPkgs == rDays) {
        curDays += rDays;
        break;
      }
      if (curSum + weights[i] > m) {
        curSum = weights[i];  // Reset
      } else {
        curSum += weights[i];
      }
    }
    if (curDays <= days) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  return ans;
}

int main() {
  vector<int> w1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int d1 = 5;
  cout << "ans1: " << shipWithinDays(w1, d1) << endl;
  vector<int> w2 = {3, 2, 2, 4, 1, 4};
  int d2 = 3;
  cout << "ans2: " << shipWithinDays(w2, d2) << endl;
  vector<int> w3 = {1, 2, 3, 1, 1};
  int d3 = 4;
  cout << "ans3: " << shipWithinDays(w3, d3) << endl;
  vector<int> w4 = {4, 2, 3};
  int d4 = 3;
  cout << "ans4: " << shipWithinDays(w4, d4) << endl;
  return 0;
}