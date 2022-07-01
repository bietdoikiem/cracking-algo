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

string Solution(vector<int>& nums, int N, int K) {
  if (K == 1) return "1 1";
  int l = 0, r = 1, d = 1;
  unordered_map<int, int> map;
  map[nums[l]] = 1;
  while (r < N) {
    // If key is distinct/not exist
    if (map.find(nums[r]) == map.end() || map[nums[r]] == 0) {
      map[nums[r]] = 1, d++;
    } else {
      map[nums[r]]++;
    }
    // Move left if enough
    if (d == K) {
      map[nums[l]]--;
      if (map[nums[l]] == 0) {
        return to_string(++l) + " " + to_string(++r);
      }
      l++;
    } else {
      r++;
    }
  }
  return "-1 -1";
}

int main() {
  // Parse input
  int N, K;
  cin >> N >> K;
  vector<int> nums(N);
  for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
  // Result
  cout << Solution(nums, N, K) << endl;
  return 0;
}