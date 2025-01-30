#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Trick Taking
//    https://atcoder.jp/contests/abc299/tasks/abc299_b



int main() {
    int N, T;
    cin >> N >> T;

    vector<int> C(N), R(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> R[i];

    int ans = -1, val = -1;
    for(int i = 0; i < N; i++) {
        if(C[i] == T) {
            if(val < R[i]) {
                ans = i + 1;
                val = R[i];
            }
        }
    }

    if(ans == -1) {
        ans = 1;
        val = R[0];
        for(int i = 1; i < N; i++) {
            if(C[0] == C[i]) {
                if(val < R[i]) {
                    ans = i + 1;
                    val = R[i];
                }
            }
        }
    }

    cout << ans << endl;
}