#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Graph Destruction
//    https://atcoder.jp/contests/abc229/tasks/abc229_e



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> Graph(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        Graph[A].push_back(B);
    }

    int cnt = 0;
    vector<int> ans(N);
    dsu UF(N);
    for(int i = N - 1; i >= 1; i--) {
        cnt++;
        for(int j : Graph[i]) {
            if(UF.same(i, j)) continue;
            UF.merge(i, j);
            cnt--;
        }
        ans[i - 1] = cnt;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}