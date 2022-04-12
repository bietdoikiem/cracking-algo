# No. 1143 - Longest Common Subsequence

## Core Concept

Longest Common Subsequence is undeniably one of the classic problems in Dynamic
Programming, in which each of the subproblems help form the bigger, final
solutions to the original problem.

In this type of problem, it's required to find the maximum common subsequence that
exist in both of the string. For that reason, for each of string traversal, the
maximum could be obtained based on different choices of choosing the starting
subsequence between those two that will be the common and longest one.

By choosing the smaller subprolem for the Dynamic Approach, the base case in
which the two of string is empty (in this problem, we're choosing the last
indexes between text1 and text2, which are their lengths). Empty string indicates that the longest common
subsequence between the two is 0; thus, it's definitely ideal to start off a DP
problem from that case. In sequence, there are 3 cases that can happen whenever
choosing the starting subsequences between the two.

> Note:
> j and i are the indexes for the characters inside text1 and text2.

By starting from their lengths (empty cases), there are 3 cases that can be
observed:

- **Case 1**: The current traversed characters between two are matched with each
  other. In that case, the subproblem of dp[i+1][j+1] (states of two strings
  excluding the current matching characters) will be used as the valid
  subproblem of the current state. Since two of the characters match, the value
  of the current state would be: 1 + dp[i+1][j+1]
- Case 2: The result for the longest common subsequence, in which the the last
  character of text1 is not in used => 1 + dp[i][j+1]
- Case 3: The result for the longest common subsequence, in which the the last
  character of text2 is not in used => 1 + dp[i+1][j]

For case 2 and case 3, since the longest one is required, the maximum between
the two values will be in used for the upcoming state.

Upon filling the table of LCS, the answer to the problem is resided in dp[0][0],
in which two of strings are completely scanned and formed based on every smaller
subproblems.

<p align="center"><img
src="https://i.ibb.co/k8dg59C/13-BFFC88-5-FB9-4-BEC-B9-DA-FA8-EAFD7-D600.jpg"
width="450"
/></p>

## Code (C++)

Given 1 <= text1,text2.length() <= 1001;

```cpp
int dp[1001][1001];

int longestCommonSubsequence(string text1, string text2):
  size_t m = text1.size();
  size_t n = text2.size();
  for (size_t i = m-1; i < m; i--) {
    for(size_t j = n-1; j < n; j--) {
      if (text1[i] == text2[j]) {
        dp[i][j] = dp[i+1][j+1];
      } else {
        dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }
  return dp[0][0];
```
