#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define endl '\n'

int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

#define MAX 200005

int T, N, S, nums[MAX];

void Solves() {
  cin >> T;
  while (T--) {
    cin >> N >> S;
    int curSum = 0;
    for (int i = 0; i < N / 2; i++) cin >> nums[i], curSum += nums[i];
    int l = 0, r = N - 1, res = 0;
    while (l < r) {
      if (curSum == S) break;
      if (curSum < S) {
        res = -1;
        break;
      }
      if (curSum > S) {
        if (nums[l] < nums[r]) {
          curSum--;
          r--;
          res++;
        } else if (nums[l] > nums[r]) {
          curSum -= 1;
          l++;
          res++;
        } else if (nums[l] == 1 && nums[r] == 1) {
          //
        }
      }
    }
    cout << (curSum == S ? to_string(res) : "-1") << endl;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  Solves();
  return 0;
}