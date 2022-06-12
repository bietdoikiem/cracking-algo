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

double calculateTax(vector<vector<int>>& brackets, int income) {
  double ans = 0.0;
  int incomeLeft = income, n = (int)brackets.size(), i = 0;
  while (incomeLeft > 0 && i < n) {
    int validUpper = min(income, brackets[i][0]);
    if (i == 0) {
      ans += validUpper * brackets[i][1] / 100.0;
      incomeLeft -= brackets[i][0];
    } else {
      ans += (validUpper - brackets[i - 1][0]) * brackets[i][1] / 100.0;
      incomeLeft -= (brackets[i][0] - brackets[i - 1][0]);
    }
    i++;
  }
  return ans;
}

int main() {
  vector<vector<int>> b1 = {{3, 50}, {7, 10}, {12, 25}};
  int i1 = 10;
  cout << "ans1: " << calculateTax(b1, i1) << endl;  // 2.65
  vector<vector<int>> b2 = {{1, 0}, {4, 25}, {5, 50}};
  int i2 = 2;
  cout << "ans2: " << calculateTax(b2, i2) << endl;  // 0.25
  vector<vector<int>> b3 = {{2, 50}};
  int i3 = 0;
  cout << "ans3: " << calculateTax(b3, i3) << endl;  // 0.0
  vector<vector<int>> b4 = {{3, 50}, {7, 10}, {12, 25}, {15, 15}};
  int i4 = 15;
  cout << "ans4: " << calculateTax(b4, i4) << endl;  // 3.6
  vector<vector<int>> b5 = {{10, 10}};
  int i5 = 5;
  cout << "ans5: " << calculateTax(b5, i5) << endl;  // 0.5
  vector<vector<int>> b6 = {{2, 7},  {3, 17},  {4, 37}, {7, 6},
                            {9, 83}, {16, 67}, {19, 29}};
  int i6 = 18;
  cout << "ans6: " << calculateTax(b6, i6) << endl;  // 7.79000
  return 0;
}