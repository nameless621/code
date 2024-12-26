#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    G - K番目の要素
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_g



int N;
long long K;
vector<long long> A, B, C;

bool check(long long X) {
    long long cnt = 0;
    for(int i = 0; i < N; i++) {
        if(X >= B[i]) {
            long long num = (X - B[i] + C[i]) / C[i];
            cnt += min(A[i], num);
        }
    }

    if(cnt >= K) return true;
    else return false;
}

int main() {
    cin >> N >> K;

    A.resize(N);
    B.resize(N);
    C.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }

    long long ng = 0, ok = 5e18;
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}