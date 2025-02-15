#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Longest Palindrome
//    https://atcoder.jp/contests/abc320/tasks/abc320_b



bool kaibun(string s) { return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()); }

int main() {
    string S;
    cin >> S;

    int N = S.size(), ans = 0;
    for(int i = 0; i < N; i++) {
        for(int len = 1; i + len <= N; len++) {
            if(kaibun(S.substr(i, len))) {
                ans = max(ans, len);
            }
        }
    }

    cout << ans << endl;
}