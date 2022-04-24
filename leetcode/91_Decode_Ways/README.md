Think of this question as [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) problem, but with a slight modification. In [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/), we are asked to take only 1 or 2 steps at a time. For that reason, a recurrence relation of the problem can be formed as the following formula: `f(n) = f(n-1) + f(n-2)` where `n` are number of stairs.

Similarly, in this problem, there are only two accepted decoded strategies for a message which are one-digit and two-digit one. So we can easily use the [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) formula to solve this problem, right? There are some constraints to this problem:

1. One-digit substring must be different from "0":
2. Two-digit substring must not have leading "0" and must be between the range [1, 26] as specified by the requirement

Therefore, the recurrence formula of this problem can only be: `f(n) = f(n-1) + f(n-2)` when they satisfied both the above constraints. If they satisfy only one of these two, just add the result for that case only.
For example:
`f(n) = f(n-1)` when satisfies 1st constraint
`f(n) = f(n-2)` when satisfies 2nd constraint
`f(n) = f(n-1) + f(n-2)` when satisfies both constraints

Here are the following code to demonstrate the above idea in C++ (17):

```cpp
class Solution {
public:
	int dp[101];

	int numDecodings(string s) {
	  int n = (int)s.size();
	  dp[0] = 1;
	  dp[1] = s.substr(0, 1) != "0" ? 1 : 0;
	  for (int i = 2; i < n + 1; i++) {
		if (stoi(s.substr(i - 1, 1)) != 0) dp[i] += dp[i - 1];
		if (s.substr(i - 2, 1) != "0") { // Skip leading zero
		  if (int td = stoi(s.substr(i - 2, 2)); td > 0 && td < 27)
			dp[i] += dp[i - 2];
		}
	  }
	  return dp[n];
	}
}
```

Since we're using only the previous result of `i-1` and `i-2`, we can optimize the space by using only two variables for storing the calculated results:

```cpp
class Solution {
public:
  int numDecodings(string s) {
    int n = (int)s.size();
    int td = 1;
    int od = s.substr(0, 1) != "0" ? 1 : 0;
    int ans = od;
    for (int i = 2; i < n + 1; i++) {
      ans = 0;
      if (stoi(s.substr(i - 1, 1)) != 0) ans += od;
      if (s.substr(i - 2, 1) != "0") { // Skip leading zero
        if (int d = stoi(s.substr(i - 2, 2)); d > 0 && d < 27) ans += td;
      }
      td = od;
      od = ans;
    }
    return ans;
  }
};
```
