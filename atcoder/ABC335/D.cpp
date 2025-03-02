#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Loong and Takahashi
//    https://atcoder.jp/contests/abc335/tasks/abc335_d



int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    A[N/2][N/2] = -1;

    int now = 1, i = 0, j = 0, k = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    while(A[i][j] != -1) {
        A[i][j] = now;
        now++;
        i += dx[k];
        j += dy[k];
        if(i < 0 || i >= N || j < 0 || j >= N || A[i][j] != 0) {
            i -= dx[k];
            j -= dy[k];
            k = (k + 1) % 4;
            i += dx[k];
            j += dy[k];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] > 0) cout << A[i][j] << " ";
            else cout << 'T' << " ";
        }
        cout << endl;
    }
}