#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Leftover Recipes
//    https://atcoder.jp/contests/abc338/tasks/abc338_c



int main() {
    int N;
    cin >> N;

    vector<int> Q(N), A(N), B(N);
    for(int i = 0; i < N; i++) cin >> Q[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    int maxA = 1e9;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) continue;
        maxA = min(maxA, Q[i] / A[i]);
    }

    int ans = maxA;
    while(maxA >= 0) {
        auto temp = Q;
        for(int i = 0; i < N; i++) {
            Q[i] -= A[i] * maxA;
        }

        int maxB = 1e9;
        for(int i = 0; i < N; i++) {
            if(B[i] == 0) continue;
            maxB = min(maxB, Q[i] / B[i]);
        }

        ans = max(ans, maxA + maxB);
        swap(Q, temp);
        maxA--;
    }

    cout << ans << endl;
}