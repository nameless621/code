#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Couples
//    https://atcoder.jp/contests/abc359/tasks/abc359_b



int main() {
    int N;
    cin >> N;
    
    N *= 2;
    vector<int> A(N);
    for(int& a : A) cin >> a;

    int ans = 0;
    for(int i = 0; i < N-2; i++) {
        if(A[i] == A[i+2]) ans++;
    }

    cout << ans << endl;
}