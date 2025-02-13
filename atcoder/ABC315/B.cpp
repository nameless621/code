#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - The Middle Day
//    https://atcoder.jp/contests/abc315/tasks/abc315_b



int main() {
    int M;
    cin >> M;

    vector<int> D(M);
    for(int i = 0; i < M; i++) cin >> D[i];

    int sum = accumulate(D.begin(), D.end(), 0);
    sum = (sum + 1) / 2;
    for(int i = 0; i < M; i++) {
        if(sum <= D[i]) {
            cout << i+1 << " " << sum << endl;
            return 0;
        }
        sum -= D[i];
    }
}