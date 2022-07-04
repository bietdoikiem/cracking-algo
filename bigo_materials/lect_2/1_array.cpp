#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int n, k;

string solution(int n, int k, vector<int> a) {
    if (k == 1) return "1 1";
    map<int, int> m;
    int l = 0, r = 1, c = 1;

    m[a[l]] = 1;
    while (r < n) {
        // If key is distinct/not exist
        if (m.find(a[r]) == m.end() || m[a[r]] == 0) {
            m[a[r]] = 1, c++;
        } else {
            m[a[r]]++;
        }
        // Move left if enough
        if (c == k) {
            m[a[l]]--;
            if (m[a[l]] == 0) {
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
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solution(n, k, a) << endl;

    return 0;
}