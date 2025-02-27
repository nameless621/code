#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - T-shirts
//    https://atcoder.jp/contests/abc332/tasks/abc332_c



int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    int ans = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            cnt1 = 0;
            cnt2 = 0;
        }
        if(S[i] == '1') {
            if(cnt2 < M) cnt2++;
            else cnt1++;
        }
        if(S[i] == '2') {
            cnt1++;
        }
        ans = max(ans, cnt1);
    }

    cout << ans << endl;
}