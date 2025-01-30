#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Transition Game
//    https://atcoder.jp/contests/abc296/tasks/abc296_e



int main() {
    int N;
    cin >> N;

    int ans = 0;
    scc_graph G(N);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        A--;
        G.add_edge(i, A);
        if(i == A) ans++;
    }

    for(auto v : G.scc()) {
        if((int)v.size() < 2) continue;
        ans += v.size();
    }

    cout << ans << endl;
}