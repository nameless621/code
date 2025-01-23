#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Maintain Multiple Sequences
//    https://atcoder.jp/contests/abc271/tasks/abc271_b



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> a(N);
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;
        a[i].resize(L);
        for(int j = 0; j < L; j++) {
            cin >> a[i][j];
        }
    }

    while(Q--) {
        int s, t;
        cin >> s >> t;
        s--; t--;
        cout << a[s][t] << endl;
    }
}