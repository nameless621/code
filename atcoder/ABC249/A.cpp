#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Jogging
//    https://atcoder.jp/contests/abc249/tasks/abc249_a



int f(int A, int B, int C, int X) {
    int res = 0;
    while(X > 0) {
        if(A <= X) {
            res += A * B;
            X -= A;
        }
        else {
            res += B * X;
            X = 0;
        }
        X -= C;
    }
    return res;
}

int main() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int res1 = f(A, B, C, X);
    int res2 = f(D, E, F, X);
    
    if(res1 > res2) cout << "Takahashi" << endl;
    else if(res1 < res2) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}