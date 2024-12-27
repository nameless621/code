#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Longest Segment
//    https://atcoder.jp/contests/abc234/tasks/abc234_b



int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    double ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int dx = X[i] - X[j];
            int dy = Y[i] - Y[j];
            double dist = sqrt(dx * dx + dy * dy);
            ans = max(ans, dist);
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}