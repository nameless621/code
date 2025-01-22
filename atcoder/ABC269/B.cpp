#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Rectangle Detection
//    https://atcoder.jp/contests/abc269/tasks/abc269_b



int main() {
    vector<string> S(10);
    for(int i = 0; i < 10; i++) cin >> S[i];

    int A = 100, B = 0, C = 100, D = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(S[i][j] == '.') continue;
            A = min(A, i + 1);
            B = max(B, i + 1);
            C = min(C, j + 1);
            D = max(D, j + 1);
        }
    }

    cout << A << " " << B << endl;
    cout << C << " " << D << endl;
}