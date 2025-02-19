#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - World Meeting
//    https://atcoder.jp/contests/abc325/tasks/abc325_b



int main() {
    int N;
    cin >> N;

    vector<int> W(N), X(N);
    for(int i = 0; i < N; i++) {
        cin >> W[i] >> X[i];
    }

    int ans = 0;
    for(int t = 0; t < 24; t++) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            int time = (X[i] + t) % 24;
            if(9 <= time && time < 18) {
                sum += W[i];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}