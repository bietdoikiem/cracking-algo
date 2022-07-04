#include <iostream>

using namespace std;

int main() {
    int N, t[100000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    int tb = 0, ta = 0;
    int i = 0, j = N - 1;

    while (i <= j) {
        if (ta + t[i] <= tb + t[j]) {
            ta += t[i];
            i++;
        } else {
            tb += t[j];
            j--;
        }
    }
    cout << i << " " << N - i << endl;
    return 0;
}