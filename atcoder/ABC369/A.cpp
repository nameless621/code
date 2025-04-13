#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - 369
//    https://atcoder.jp/contests/abc369/tasks/abc369_a



int main() {
    int A, B;
    cin >> A >> B;

    int ans = 0;
    for(int x = -200; x <= 200; x++) {
        vector<int> P = {A, B, x};
        sort(P.begin(), P.end());
        do {
            if(P[1] - P[0] == P[2] - P[1]) {
                ans++;
                break;
            }
        } while(next_permutation(P.begin(), P.end()));
    }

    cout << ans << endl;
}