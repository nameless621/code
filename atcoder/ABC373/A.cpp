#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - September
//    https://atcoder.jp/contests/abc373/tasks/abc373_a



int main() {
    int ans = 0;

    for(int i = 1; i <= 12; i++) {
        string S;
        cin >> S;
        if((int)S.size() == i) ans++;
    }
    
    cout << ans << endl;
}