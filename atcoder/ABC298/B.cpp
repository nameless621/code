#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Coloring Matrix
//    https://atcoder.jp/contests/abc298/tasks/abc298_b



vector<vector<int>> rot(vector<vector<int>> &A, int N) {
    vector<vector<int>> res(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res[i][j] = A[N-j-1][i];
        }
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    bool ok = false;
    for(int k = 0; k < 4; k++) {
        bool flag = true;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(B[i][j] == 0 && A[i][j] == 1) {
                    flag = false;
                }
            }
        }
        if(flag) ok = true;
        A = rot(A, N);
    }

    cout << (ok ? "Yes" : "No") << endl;
}