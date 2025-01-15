#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Index Trio
//    https://atcoder.jp/contests/abc249/tasks/abc249_d



int main() {
    int N, M = 2e5;
    cin >> N;

    vector<long long> cnt(M+1);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cnt[A]++;
    }

    long long ans = 0;
    for(int j = 1; j <= M; j++) {
        for(int k = 1; j * k <= M; k++) {
            ans += cnt[j] * cnt[k] * cnt[j * k];
        }
    }

    cout << ans << endl;
}