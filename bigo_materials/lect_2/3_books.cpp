#include <iostream>
#include <vector>

using namespace std;

int main() {
    int max_book = 0;
    int start_book = 0;
    int read_time = 0;

    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int end_book = 0; end_book < N; end_book++) {
        // thử lấy end_book
        read_time += A[end_book];
        // nếu tổng từ start_book -> end_book bị lố T thì ta chỉ cần
        // loại start_book mà không cần thay đổi end_book
        while (read_time > T) {
            read_time -= A[start_book];
            start_book++;
        }
        // đến đây thì read_time chác chắn <= T
        max_book = max(max_book, end_book - start_book + 1);
    }

    cout << max_book << endl;

    return 0;
}