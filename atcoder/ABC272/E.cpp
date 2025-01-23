#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Add and Mex
//    https://atcoder.jp/contests/abc272/tasks/abc272_e



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<set<int>> res(M+1);
    for(int i = 0; i < N; i++) {
        long long ng = -1, ok = 1e9;
        while(abs(ok - ng) > 1) {
            long long mid = (ok + ng) / 2;
            if(0 <= A[i] + mid * (i+1)) ok = mid;
            else ng = mid;
        }
        for(int j = ok; j <= M; j++) {
            long long x = A[i] + j * (i + 1);
            if(x > N) break;
            res[j].insert(x);
        }
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 0; j <= N; j++) {
            if(!res[i].count(j)) {
                cout << j << endl;
                break;
            }
        }
    }
}