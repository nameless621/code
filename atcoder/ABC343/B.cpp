#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Adjacency Matrix
//    https://atcoder.jp/contests/abc343/tasks/abc343_b



int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j]) cout << j + 1 << " ";
        }
        cout << endl;
    }
}