#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Election Quick Report 
//    https://atcoder.jp/contests/abc329/tasks/abc329_d



int main() {
    int N, M;
    cin >> N >> M;

    int res = 0;
    vector<int> cnt(N);
    while(M--) {
        int A;
        cin >> A, A--;
        cnt[A]++;
        if(cnt[res] < cnt[A]) res = A;
        else if(cnt[res] == cnt[A]) res = min(res, A);
        cout << res + 1 << '\n';
    }
}