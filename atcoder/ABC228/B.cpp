#include <bits/stdc++.h>
using namespace std;


//    B - Takahashi's Secret
//    https://atcoder.jp/contests/abc228/tasks/abc228_b



int main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    int now = X - 1, ans = 1;
    vector<bool> ok(N);
    ok[now] = true;
    now = A[now];
    while(!ok[now]) {
        ok[now] = true;
        now = A[now];
        ans++;
    }

    cout << ans << endl;
}