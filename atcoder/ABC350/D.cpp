#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - New Friends
//    https://atcoder.jp/contests/abc350/tasks/abc350_d



int main() {
    int N, M;
    cin >> N >> M;

    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        uf.merge(A, B);
    }

    long long ans = -M;
    for(int i = 0; i < N; i++) {
        if(uf.leader(i) != i) continue;
        long long siz = uf.size(i);
        ans += siz * (siz-1) / 2;
    }

    cout << ans << endl;
}