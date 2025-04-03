#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Second Best
//    https://atcoder.jp/contests/abc365/tasks/abc365_b



int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].first;
        P[i].second = i + 1;
    }

    sort(P.rbegin(), P.rend());
    cout << P[1].second << endl;
}