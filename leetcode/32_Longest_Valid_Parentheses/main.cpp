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

int max(int x, int y) { return x > y ? x : y; }

// longestValidParentheses return the longest number of valid parentheses in the
// given string
int longestValidParentheses(string s) {
  size_t n = s.size();
  stack<int> st;
  int cur = 0;
  int ans = 0;
  st.push(-1);
  for (size_t i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      st.pop();
      if (st.empty()) {
        st.push(i);
        cur = 0;
        continue;
      }
      if (st.size() >= 1) {
        ans = max(ans, i - st.top());
        continue;
      }
    }
  }
  return ans;
}

int main() {
  string s = ")()())";
  cout << longestValidParentheses(s) << endl;
  return 0;
}