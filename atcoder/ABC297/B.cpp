#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - chess960
//    https://atcoder.jp/contests/abc297/tasks/abc297_b



int main() {
    string S;
    cin >> S;

    int N = S.size();
    int Bx = -1, By = -1, Rx = -1, Ry = -1, z = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'B') {
            if(Bx == -1) Bx = i;
            else By = i;
        }
        if(S[i] == 'R') {
            if(Rx == -1) Rx = i;
            else Ry = i;
        }
        if(S[i] == 'K') {
            z = i;
        }
    } 

    bool ok = true;
    if(~(Bx + By) & 1) ok = false;
    if(z < Rx || Ry < z) ok =false;

    cout << (ok ? "Yes" : "No") << endl;
}