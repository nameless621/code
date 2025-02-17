#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - First ABC 2
//    https://atcoder.jp/contests/abc322/tasks/abc322_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = -1;
    for(int i = 0; i <= N - 3; i++) {
        if(S.substr(i, 3) == "ABC") {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
}