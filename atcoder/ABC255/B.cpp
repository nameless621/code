#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Light It Up
//    https://atcoder.jp/contests/abc255/tasks/abc255_b



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(K);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    double ans = 0;
    for(int i = 0; i < N; i++) {
        double res = DBL_MAX;
        auto[x1, y1] = P[i];
        for(int j = 0; j < K; j++) {
            auto[x2, y2] = P[A[j]];
            double X = x1 - x2;
            double Y = y1 - y2;
            double D = sqrt(X * X + Y * Y);
            res = min(res, D);
        }
        ans = max(ans, res);
    }

    cout << fixed << setprecision(12) << ans << endl;
}