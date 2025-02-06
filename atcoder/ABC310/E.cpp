#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - NAND repeatedly
//    https://atcoder.jp/contests/abc310/tasks/abc310_e



int main() {
    int N;
    string S;
    cin >> N >> S;

    long long ans = 0;
    vector<long long> cnt(2);
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            ans += cnt[0] + cnt[1];
            cnt[1] += cnt[0];
            cnt[0] = 1;
        }
        else {
            ans += cnt[0] + 1;
            swap(cnt[0], cnt[1]);
            cnt[1]++;
        }
    }

    cout << ans << endl;
}