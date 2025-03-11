#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Square Pair
//    https://atcoder.jp/contests/abc342/tasks/abc342_d



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    long long ans = 0;
    unordered_map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            ans += N - i - 1;
            continue;
        }
        int res = 1;
        for(int p = 2; p*p <= A[i]; p++) {
            if(A[i] % p) continue;
            int e = 0;
            while(A[i] % p == 0) {
                A[i] /= p;
                e++;
            }
            if(e & 1) res *= p;
        }
        if(A[i] != 1) res *= A[i];
        cnt[res]++;
    }

    for(auto[k, v] : cnt) {
        ans += (long long)v * (v - 1) / 2;
    }

    cout << ans << endl;
}