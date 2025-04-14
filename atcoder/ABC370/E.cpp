#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Avoid K Partition
//    https://atcoder.jp/contests/abc370/tasks/abc370_e



int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    vector<long long> S(N+1);
    for(int i = 0; i < N; i++) {
        S[i+1] = S[i] + A[i];
    }

    mint sum = 1;
    unordered_map<long long, mint> cnt;
    cnt[0] = 1;
    for(int i = 1; i <= N; i++) {
        mint temp = sum;
        temp -= cnt[S[i] - K];
        sum += temp;
        cnt[S[i]] += temp;
        if(i == N) cout << temp.val() << endl;
    }
}