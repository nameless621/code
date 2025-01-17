#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Practical Computing
//    https://atcoder.jp/contests/abc254/tasks/abc254_b



int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> A(N, vector<int>(N));
    A[0][0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i) A[i][j] = 1;
            else A[i][j] = A[i-1][j-1] + A[i-1][j];
        }
    }

    for(int i = 0; i < N ;i++) {
        for(int j = 0; j <= i; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}