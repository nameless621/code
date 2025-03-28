#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Count Takahashi
//    https://atcoder.jp/contests/abc359/tasks/abc359_a



int main() {
    int N;
    cin >> N;

    int ans = 0;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if(S == "Takahashi") ans++;
    }

    cout << ans << endl;
}