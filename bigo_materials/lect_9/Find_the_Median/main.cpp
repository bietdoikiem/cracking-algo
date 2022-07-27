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

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

/***** SOLUTION BELOW HERE *****/

#define MAX 1000005
int n, res, nums[MAX];

int partition(int l, int r) {
  int pivot = nums[r], i = l;
  for (int j = l; j < r; j++) {
    if (nums[j] <= pivot) swap(nums[i], nums[j]), i++;
  }
  swap(nums[i], nums[r]);
  return i;
}

int quickSelect(int l, int r, int k) {
  if (k < 0 || k > r - l + 1) return INT_MAX;
  int idx = partition(l, r);
  if (idx - l + 1 == k) return nums[idx];
  if (idx - l + 1 > k) return quickSelect(l, idx - 1, k);
  return quickSelect(idx + 1, r, k - (idx - l + 1));
}

void Solves() {
  cin >> n;
  int k = (n / 2) + 1;
  for (int i = 0; i < n; i++) cin >> nums[i];
  cout << quickSelect(0, n - 1, k) << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}