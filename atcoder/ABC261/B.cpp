#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Tournament Result
//    https://atcoder.jp/contests/abc254/tasks/abc261_b



int main() {
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    bool ok = true;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(A[i][j] == 'W' && A[j][i] != 'L') ok = false;
            if(A[i][j] == 'L' && A[j][i] != 'W') ok = false;
            if(A[i][j] == 'D' && A[j][i] != 'D') ok = false;
        }
    }

    cout << (ok ? "correct" : "incorrect") << endl;
}