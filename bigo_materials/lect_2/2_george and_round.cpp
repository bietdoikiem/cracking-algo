#include <iostream>
#include <vector>

using namespace std;

int solution(int N, int M, vector<int> A, vector<int> B) {
    int res = N, a = 0, b = 0;
    while (a < N && b < M) {
        if (A[a] <= B[b]) {
            a++, b++, res--;
        } else {
            b++;
        }
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    cout << solution(N, M, A, B) << endl;

    return 0;
}