#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Index × A(Continuous ver.) 
//    https://atcoder.jp/contests/abc267/tasks/abc267_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long sum = 0, temp = 0;
    for(int i = 0; i < M; i++) {
        sum += A[i] * (i + 1);
        temp += A[i];
    }

    long long ans = sum;
    for(int i = M; i < N; i++) {
        sum = sum - (temp - A[i] * M);
        temp = temp - A[i - M] + A[i];
        ans = max(ans, sum);
    }

    cout << ans << endl;
}