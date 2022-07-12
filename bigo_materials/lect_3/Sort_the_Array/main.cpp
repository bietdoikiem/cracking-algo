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

void Solves(vector<int>& nums, int n) {
  int l = 0, r = 0, last = 0, lastBeforeSeg = 0;
  char flag = 0;  // 0 - unset | 1 - in-set | 2 - already-set
  for (int i = 0; i < n; i++) {
    if (nums[i] < lastBeforeSeg) {
      cout << "no" << endl;
      return;
    }
    if (nums[i] < last) {
      if (flag == 0) {
        l = i - 1, flag = 1;
        if (l - 1 >= 0) lastBeforeSeg = nums[l - 1];
      } else if (flag == -1) {
        cout << "no" << endl;
        return;
      }
    } else {
      if (flag == 1) {
        if (nums[i] > nums[l]) {
          r = i - 1, flag = -1;
        } else {
          cout << "no" << endl;
          return;
        }
      }
    }
    last = nums[i];
  }
  if (flag == 1) r = n - 1;  // In-set at last elem
  cout << "yes" << endl;
  cout << l + 1 << " " << r + 1 << endl;
  return;
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) cin >> nums[i];
  Solves(nums, n);
  return 0;
}