#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Bus Stops
//    https://atcoder.jp/contests/abc319/tasks/abc319_e



int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> P(N), T(N);
    for(int i = 0; i < N - 1; i++) {
        cin >> P[i] >> T[i];
    }

    int M = 840;
    vector<long long> dist(M);
    for(int k = 0; k < M; k++) {
        long long res = k + X;
        for(int i = 0; i < N - 1; i++) {
            if(res % P[i]) res = ((res + P[i] - 1) / P[i]) * P[i];
            res += T[i];
        }
        dist[k] = res + Y;
    }

    int Q;
    cin >> Q;
    while(Q--) {
        long long q;
        cin >> q;
        long long res = (q - q % M) + dist[q % M];
        cout << res << '\n';
    }
}