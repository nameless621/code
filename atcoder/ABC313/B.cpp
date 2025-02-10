#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Who is Saikyo?
//    https://atcoder.jp/contests/abc313/tasks/abc313_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cnt(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        B--;
        cnt[B]++;
    }

    int ans = -1;
    for(int i = 0; i < N; i++) {
        if(cnt[i]) continue;
        if(ans != -1) {
            cout << -1 << endl;
            return 0;
        }
        ans = i + 1;
    }

    cout << ans << endl;
}