#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Default Price
//    https://atcoder.jp/contests/abc308/tasks/abc308_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<string> C(N), D(M);
    vector<int> P(M+1);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> D[i];
    for(int i = 0; i < M+1; i++) cin >> P[i];

    map<string, int> mp;
    for(int i = 0; i < M; i++) {
        mp[D[i]] = P[i+1];
    }

    int res = 0;
    for(int i = 0; i < N; i++) {
        if(mp.count(C[i])) res += mp[C[i]];
        else res += P[0];
    }

    cout << res << endl;
}