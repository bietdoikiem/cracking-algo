#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int N, int M, int X, int Y, vector<int> A, vector<int> B) {
    vector<string> res;
    int i = 0, j = 0;
    while (i < N && j < M) {
        if ((A[i] - X <= B[j]) && (B[j] <= A[i] + Y)) {
            res.push_back(to_string(i + 1) + " " + to_string(j + 1));
            i++, j++;
        } else if ((A[i] - X > B[j])) {
            j++;
        } else if ((A[i] + Y < B[j]))
            i++;
    }

    cout << res.size() << endl;
    for (auto& str : res) {
        cout << str << endl;
    }
}

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    vector<int> A(N), B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    solution(N, M, X, Y, A, B);

    return 0;
}