#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Scoreboard 
//    https://atcoder.jp/contests/abc337/tasks/abc337_a



int main() {
    int N;
    cin >> N;

    int T = 0, A = 0;
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        T += X;
        A += Y;
    }

    if(T > A) cout << "Takahashi" << endl;
    else if(T < A) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}