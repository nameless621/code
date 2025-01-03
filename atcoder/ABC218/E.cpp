#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Destruction 
//    https://atcoder.jp/contests/abc218/tasks/abc218_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> P;
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        P.emplace_back(C, A, B);
    }

    sort(P.begin(), P.end());

    long long ans = 0;
    dsu uf(N);
    for(int i = 0; i < M; i++) {
        auto[C, A, B] = P[i];
        if(uf.same(A, B)) {
            if(C > 0) ans += C;
            continue;
        }
        uf.merge(A, B);
    }

    cout << ans << endl;
}