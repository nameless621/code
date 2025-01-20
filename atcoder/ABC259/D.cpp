#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Circumferences
//    https://atcoder.jp/contests/abc254/tasks/abc259_d



int main() {
    int N, sx, sy, tx, ty;
    cin >> N >> sx >> sy >> tx >> ty;

    vector<tuple<long long, long long, long long>> P;
    for(int i = 0; i < N; i++) {
        long long x, y, r;
        cin >> x >> y >> r;
        P.emplace_back(x, y, r);
    }

    P.emplace_back(sx, sy, 0);
    P.emplace_back(tx, ty, 0);
    N += 2;
    int s = N - 2, t = N - 1;

    dsu uf(N);
    for(int i = 0; i < N; i++) {
        auto[x1, y1, r1] = P[i];
        for(int j = 0; j < N; j++) {
            auto[x2, y2, r2] = P[j];
            long long X = x1 - x2;
            long long Y = y1 - y2;
            long long D = X * X + Y * Y;
            if(D < (r1 - r2) * (r1 - r2)) continue;
            if(D > (r1 + r2) * (r1 + r2)) continue;
            uf.merge(i, j);
        }
    }

    cout << (uf.same(s, t) ? "Yes" : "No") << endl;
}