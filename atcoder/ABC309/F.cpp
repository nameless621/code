#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Box in Box
//    https://atcoder.jp/contests/abc309/tasks/abc309_f



int op(int a, int b) { return min(a, b); }
int e() { return 2e9; }

vector<int> compress(auto& x) {
    auto y = x;
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    vector<int> res(x.size());
    for(int i = 0; i < (int)x.size(); i++) {
        int num = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
        res[i] = num;
    }
    return res;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> P(N, vector<int>(3));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> P[i][j];
        }
        sort(P[i].begin(), P[i].end());
    }

    sort(P.begin(), P.end(), [&](vector<int>& A, vector<int>& B) {
        if(A[0] != B[0]) return A[0] < B[0];
        return A[1] > B[1];
    });

    vector<int> w(N);
    for(int i = 0; i < N; i++) w[i] = P[i][1];
    auto res = compress(w);

    segtree<int, op, e> seg(N);
    bool ok = false;
    for(int i = 0; i < N; i++) {
        int d = seg.prod(0, res[i]);
        if(d < P[i][2]) ok = true;
        seg.set(res[i], min(seg.get(res[i]), P[i][2]));
    }

    cout << (ok ? "Yes" : "No") << endl;
}