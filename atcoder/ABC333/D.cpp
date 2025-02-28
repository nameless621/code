#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Erase Leaves
//    https://atcoder.jp/contests/abc333/tasks/abc333_d



int main() {
    int N;
    cin >> N;

    dsu d(N);
    for(int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(u == 0) continue;
        else d.merge(u, v);
    }

    vector<int> cc;
    for(int i = 1; i < N; i++) {
        if(d.leader(i) == i) {
            cc.push_back(d.size(i));
        }
    }

    int sum = accumulate(cc.begin(), cc.end(), 0);
    cout << sum - *max_element(cc.begin(), cc.end()) + 1 << endl;
}