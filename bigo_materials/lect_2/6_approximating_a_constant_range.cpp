#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<int> arr) {
    if (N == 1) return 1;
    int min = arr[0], i = 0, j = 1;

    return j - i + 1;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    return 0;
}