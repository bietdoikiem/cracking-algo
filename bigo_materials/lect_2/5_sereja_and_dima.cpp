#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 0, r = N - 1;
    int sumS = 0, sumD = 0;
    bool isS = true;

    while (l <= r) {
        if (isS)
            sumS += max(arr[l], arr[r]);
        else
            sumD += max(arr[l], arr[r]);

        if (arr[l] > arr[r]) {
            l++;
        } else {
            r--;
        }

        isS = !isS;
    }

    cout << sumS << " " << sumD << endl;

    return 0;
}