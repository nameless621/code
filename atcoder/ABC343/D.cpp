#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Diversity of Scores
//    https://atcoder.jp/contests/abc343/tasks/abc343_d



int main() {
    int N, T;
    cin >> N >> T;
    
    vector<int> A(T), B(T);
    for(int i = 0; i < T; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
    }

    vector<long long> sum(N);
    unordered_map<long long, int> cnt;
    cnt[0] = N;
    for(int i = 0; i < T; i++) {
        cnt[sum[A[i]]]--;
        if(cnt[sum[A[i]]] == 0) cnt.erase(sum[A[i]]);
        sum[A[i]] += B[i];
        cnt[sum[A[i]]]++;
        cout << cnt.size() << endl;
    }
}