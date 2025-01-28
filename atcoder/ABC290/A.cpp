#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Contest Result
//    https://atcoder.jp/contests/abc290/tasks/abc290_a



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for(int i = 0; i < M; i++) {
        int B;
        cin >> B, B--;
        ans += A[B];
    }

    cout << ans << endl;
}