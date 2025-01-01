#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Maritozzo
//    https://atcoder.jp/contests/abc219/tasks/abc219_b



int main() {
    string S[3], T;
    cin >> S[0] >> S[1] >> S[2] >> T;

    string ans;
    for(int i = 0; i <(int)T.size(); i++) {
        int x = T[i] - '1';
        ans += S[x];
    }

    cout << ans << endl;
}