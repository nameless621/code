#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Set Meal
//    https://atcoder.jp/contests/abc331/tasks/abc331_e



int main() {
    int N, M, L;
    cin >> N >> M >> L;

    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    
    vector<pair<int, int>> b;
    for(int i = 0; i < M; i++) {
        int cost;
        cin >> cost;
        b.emplace_back(cost, i);
    }
    sort(b.rbegin(), b.rend());

    set<pair<int, int>> s;
    for(int i = 0; i < L; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        s.emplace(c, d);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(auto[cost, j] : b) {
            if(s.count({i, j})) continue;
            ans = max(ans, a[i] + cost);
            break;
        }
    }

    cout << ans << endl;
}