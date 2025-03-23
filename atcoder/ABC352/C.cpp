#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Standing On The Shoulders
//    https://atcoder.jp/contests/abc352/tasks/abc352_c



int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    sort(P.begin(), P.end(), [&](pair<int, int>& L, pair<int, int>& R) {
        int x = abs(L.first - L.second);
        int y = abs(R.first - R.second);
        return x < y;
    });

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        if(i < N-1) {
            ans += P[i].first;
        }
        else {
            ans += P[i].second;
        }
    }

    cout << ans << endl;
}