#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Sum of Numbers Greater Than Me
//    https://atcoder.jp/contests/abc331/tasks/abc331_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> temp = A;
    sort(A.begin(), A.end());
    
    vector<long long> S(N+1);
    for(int i = 0; i < N; i++) S[i+1] = S[i] + A[i];

    for(int i = 0; i < N; i++) {
        int j = upper_bound(A.begin(), A.end(), temp[i]) - A.begin();
        long long res = S[N] - S[j];
        cout << res << (i < N-1 ? ' ' : '\n');
    }
}