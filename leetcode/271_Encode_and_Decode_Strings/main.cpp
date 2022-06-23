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

string encode(vector<string>& strs) {
  string encodedStr;
  for (auto& s : strs) encodedStr += to_string(s.size()) + "#" + s;
  return encodedStr;
}

vector<string> decode(string s) {
  vector<string> tokens;
  int tokenLen = -1;
  string tmpLen, tmpToken;
  for (auto& c : s) {
    if (tokenLen == -1) {
      if (c == '#') {
        tokenLen = stoi(tmpLen);
      } else {
        tmpLen.push_back(c);
      }
    } else {
      tmpToken.push_back(c);
      tokenLen--;
    }
    // Check end of token
    if (tokenLen == 0) {
      tokens.push_back(tmpToken), tmpToken.clear();  // Reset token
      tokenLen = -1, tmpLen.clear();                 // Reset lengths
    }
  }
  return tokens;
}

int main() {
  vector<string> strs1 = {"Hello", "World"};
  cout << encode(strs1) << endl;
  vector<string> decode1 = decode(encode(strs1));
  cout << "decode1: " << decode1 << " - length: " << decode1.size() << endl;
  vector<string> strs2 = {""};
  cout << encode(strs2) << endl;
  vector<string> decode2 = decode(encode(strs2));
  cout << "decode2: " << decode2 << " - length: " << decode2.size() << endl;
  vector<string> strs3 = {"\""};
  cout << encode(strs3) << endl;
  vector<string> decode3 = decode(encode(strs3));
  cout << "decode3: " << decode3 << " - length: " << decode3.size() << endl;
  return 0;
}