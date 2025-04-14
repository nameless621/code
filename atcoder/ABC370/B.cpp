#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Binary Alchemy
//    https://atcoder.jp/contests/abc370/tasks/abc370_b



int main() {
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i+1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    int i = 0;
    for(int j = 0; j < N; j++) {
        if(i >= j) i = A[i][j];
        else i = A[j][i];
    }

    cout << i+1 << endl;
}