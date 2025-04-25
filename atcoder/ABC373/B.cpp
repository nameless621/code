#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - 1D Keyboard
//    https://atcoder.jp/contests/abc373/tasks/abc373_b



int main() {
    string S;
    cin >> S;

    map<char, int> pos;
    for(int i = 0; i < 26; i++) {
        pos[S[i]] = i;
    }

    int ans = 0, now = pos['A'];
    for(char c = 'A'; c <= 'Z'; c++) {
        ans += abs(pos[c] - now);
        now = pos[c];
    }

    cout << ans << endl;
}