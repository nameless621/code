#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Invisible Hand
//    https://atcoder.jp/contests/abc312/tasks/abc312_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    auto check = [&](int x) {
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] <= x) cnt1++;
        }
        for(int i = 0; i < M; i++) {
            if(B[i] >= x) cnt2++;
        }
        return cnt1 >= cnt2;
    };

    int ng = 0, ok = 1001001001;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}