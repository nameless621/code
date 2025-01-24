#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - ^{-1}
//    https://atcoder.jp/contests/abc277/tasks/abc277_a



int main() {
    int N, X;
    cin >> N >> X;

    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << find(P.begin(), P.end(), X) - P.begin() + 1 << endl;
}