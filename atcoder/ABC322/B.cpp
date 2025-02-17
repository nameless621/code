#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Prefix and Suffix
//    https://atcoder.jp/contests/abc322/tasks/abc322_b



int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    string prefix = T.substr(0, N);
    string suffix = T.substr(M - N, N);
    
    int ans = -1;
    if(S == prefix && S == suffix) ans = 0;
    else if(S == prefix) ans = 1;
    else if(S == suffix) ans = 2;
    else ans = 3;

    cout << ans << endl;
}