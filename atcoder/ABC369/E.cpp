#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Sightseeing Tour
//    https://atcoder.jp/contests/abc369/tasks/abc369_e



int main() {
    int N, M;
    cin >> N >> M;

    long long INF = 1e18;
    vector<vector<long long>> dist(N, vector<long long>(N, INF));
    for(int i = 0; i < N; i++) dist[i][i] = 0;

    vector<tuple<int, int, long long>> E;
    for(int i = 0; i < M; i++) {
        int U, V;
        long long T;
        cin >> U >> V >> T;
        U--; V--;
        dist[U][V] = min(dist[U][V], T);
        dist[V][U] = min(dist[V][U], T);
        E.emplace_back(U, V, T);
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int K;
        cin >> K;
        vector<int> B(K);
        for(int& b : B) cin >> b, b--;
        
        long long ans = INF;
        do {
            for(int bit = 0; bit < (1 << K); bit++) {
                int now = 0;
                long long sum = 0;
                for(int i = 0; i < K; i++) {
                    auto[a, b, c] = E[B[i]];
                    if(bit >> i & 1) {
                        sum += dist[now][a] + c;
                        now = b;
                    }
                    else {
                        sum += dist[now][b] + c;
                        now = a;
                    }
                }
                sum += dist[now][N-1];
                ans = min(ans, sum);
            }
        } while(next_permutation(B.begin(), B.end()));

        cout << ans << '\n';
    }
}