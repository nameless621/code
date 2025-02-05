#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Vouchers
//    https://atcoder.jp/contests/abc308/tasks/abc308_f



int main() {
    int N, M;
    cin >> N >> M;

    multiset<int> P;
    vector<int> L(M), D(M);
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        P.insert(x);
    }
    for(int i = 0; i < M; i++) cin >> L[i];
    for(int i = 0; i < M; i++) cin >> D[i];

    vector<pair<int, int>> Q;
    for(int i = 0; i < M; i++) {
        Q.emplace_back(D[i], L[i]);
    }

    sort(Q.rbegin(), Q.rend());

    long long ans = 0;
    for(int i = 0; i < M; i++) {
        auto[D, L] = Q[i];
        auto itr = P.lower_bound(L);
        if(itr == P.end()) continue;
        ans += *itr - D;
        P.erase(itr);
    }

    for(int num : P) ans += num;
    cout << ans << endl;
}