#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Potions
//    https://atcoder.jp/contests/abc317/tasks/abc317_a



int main() {
    int N, H, X;
    cin >> N >> H >> X;

    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    for(int i = 0; i < N; i++) {
        if(H + P[i] >= X) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}