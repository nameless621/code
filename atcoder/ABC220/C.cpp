#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Long Sequence
//    https://atcoder.jp/contests/abc220/tasks/abc220_c



int main() {
    int N;
    cin >> N;

    long long sum = 0;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    long long X;
    cin >> X;

    long long ans = X / sum * N;
    X %= sum;

    for(int i = 0; i < N; i++) {
        ans++;
        X -= A[i];
        if(X < 0) break;
    }

    cout << ans << endl;
}