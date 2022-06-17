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

int letters[26];

string hashKey(string& s) {
  memset(letters, 0, sizeof(letters));  // Reset count
  string key;
  for (auto& c : s) letters[c - 'a']++;  // Count freq
  for (auto& freq : letters) key.append("#"), key.append(to_string(freq));
  return key;
}

// groupAnagramsByCount groups anagrams by count/frequency of existing letters
vector<vector<string>> groupAnagramsByCount(vector<string>& strs) {
  vector<vector<string>> res;
  unordered_map<string, vector<string>> anagrams;
  for (auto& str : strs) {
    string key = hashKey(str);
    if (anagrams.find(key) == anagrams.end()) {
      anagrams[key] = {str};
    } else {
      anagrams[key].push_back(str);
    }
  }
  for (auto& a : anagrams) res.push_back(a.second);
  return res;
}

vector<vector<string>> groupAnagramsBySort(vector<string>& strs) {
  vector<vector<string>> res;
  unordered_map<string, vector<string>> anagrams;
  for (auto& str : strs) {
    string key = str;
    sort(key.begin(), key.end());
    if (anagrams.find(key) == anagrams.end()) {
      anagrams[key] = {str};
    } else {
      anagrams[key].push_back(str);
    }
  }
  for (auto& a : anagrams) res.push_back(a.second);
  return res;
}

int main() {
  vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
  cout << "res1: " << groupAnagramsBySort(strs1) << endl;
  vector<string> strs2 = {"", ""};
  cout << "res2: " << groupAnagramsBySort(strs2) << endl;
  return 0;
}