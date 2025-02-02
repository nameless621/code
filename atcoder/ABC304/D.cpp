#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - A Piece of Cake
//    https://atcoder.jp/contests/abc304/tasks/abc304_d



int main() {
    int W, H, N;
    cin >> W >> H >> N;

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    int A;
    cin >> A;
    vector<int> a(A);
    for(int i = 0; i < A; i++) cin >> a[i];

    int B;
    cin >> B;
    vector<int> b(B);
    for(int i = 0; i < B; i++) cin >> b[i];

    a.push_back(W);
    b.push_back(H);

    map<pair<int, int>, int> cnt;
    for(int k = 0; k < N; k++) {
        auto[x, y] = P[k];
        int i = lower_bound(a.begin(), a.end(), x) - a.begin();
        int j = lower_bound(b.begin(), b.end(), y) - b.begin();
        cnt[{i, j}]++;
    }

    int MIN = N, MAX = 0;
    for(auto[key, val] : cnt) {
        MIN = min(MIN, val);
        MAX = max(MAX, val);
    }

    if((int)cnt.size() < (long long)(A+1) * (B+1)) MIN = 0;
    cout << MIN << " " << MAX << endl;
}