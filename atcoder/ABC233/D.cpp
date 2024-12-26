#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Count Interval
//    https://atcoder.jp/contests/abc233/tasks/abc233_d



int main() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> prefix_sum(N + 1);
    for(int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    long long ans = 0;
    map<long long, int> count;
    //  S[r] - S[l] = K → S[r] - K = S[l]
    for(int i = 0; i < N + 1; i++) {
        ans += count[prefix_sum[i] - K];
        count[prefix_sum[i]]++;
    }

    cout << ans << endl;
}