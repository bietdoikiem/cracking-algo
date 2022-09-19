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

int main() {
  vector<string> taskIds = {"id442",  "id2444", "id424",
                            "id4242", "id999",  "id666"};
  unordered_map<string, int> taskMapIdx;
  for (int i = 0; i < (int)taskIds.size(); i++) {
    taskMapIdx[taskIds[i]] = i;
  }
  // async wrapRunTask(id, executionOrder) {
  //   await runTask(id);
  //   executionOrder.push(taskMapIdx[id]);
  // }
  // await Promise.all([wrapRunTask("id442"), wrapRunTask("id2444"), ...]);
  vector<int> orders = {0, 2, 1, 3};
  vector<int> ans(orders.size(), -2);
  for (int i = 0; i < (int)ans.size(); i++) {
    if (orders[i] == 0) {
      ans[orders[i]] = 0;
    } else {
      ans[orders[i]] = ans[orders[i] - 1] != -2 ? orders[i] : -1;
    }
  }
  cout << ans << endl;
  return 0;
}