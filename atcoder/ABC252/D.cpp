#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Distinct Trio
//    https://atcoder.jp/contests/abc250/tasks/abc252_d



long long nC2(long long n) { return n * (n - 1) / 2; }
long long nC3(long long n) { return n * (n - 1) * (n - 2) / 6; }

int main() {
    int N;
    cin >> N;

    int M = 2e5 + 9;
    vector<int> cnt(M);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cnt[A]++;
    }

    long long ans = nC3(N);
    for(int i = 0; i < M; i++) {
        ans -= nC2(cnt[i]) * (N - cnt[i]);
        ans -= nC3(cnt[i]);
    }

    cout << ans << endl;
}