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

struct TopicData {
  ll id, z, p, l, c, s, ch, nz;
};

struct compare {
  bool operator()(const TopicData& a, const TopicData& b) {
    if (a.ch < b.ch) {
      return true;
    } else if (a.ch == b.ch) {
      return a.id < b.id;
    }
    return false;
  }
};

const int POST_SCORE = 50, LIKE_SCORE = 5, COMMENT_SCORE = 10, SHARE_SCORE = 20;
ll N, ID, Z, P, L, C, S, ch, nz;
priority_queue<TopicData, vector<TopicData>, compare> pq;

void Solves() {
  for (int i = 0; i < N; i++) {
    cin >> ID >> Z >> P >> L >> C >> S;
    nz = P * POST_SCORE + L * LIKE_SCORE + C * COMMENT_SCORE + S * SHARE_SCORE;
    ch = nz - Z;
    TopicData t = {ID, Z, P, L, C, S, ch, nz};
    pq.push(t);
  }
  for (int i = 0; i < 5; i++) {
    TopicData t = pq.top();
    pq.pop();
    cout << t.id << " " << t.nz << endl;
  }
  return;
}

int main() {
  freopen("input.txt", "r", stdin);
  cin >> N;
  Solves();
  return 0;
}