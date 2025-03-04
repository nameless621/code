#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Lining Up 2
//    https://atcoder.jp/contests/abc337/tasks/abc337_c



int main() {
    int N;
    cin >> N;

    int now = -1;
    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if(A == -1) now = i;
        else {
            A--;
            G[A].push_back(i);
        }
    }

    vector<int> res = {now};
    while((int)res.size() < N) {
        for(int nex : G[now]) {
            res.push_back(nex);
            now = nex;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << res[i] + 1 << (i < N-1 ? " " : "\n");
    }
}