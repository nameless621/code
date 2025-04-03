#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Transportation Expenses
//    https://atcoder.jp/contests/abc365/tasks/abc365_c



int main() {
    int N;
    long long M;
    cin >> N >> M;

    vector<long long> A(N);
    for(auto& a : A) cin >> a;

    auto check = [&](long long x) {
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            sum += min(x, A[i]);
        }
        return sum <= M;
    };

    long long INF = 1e18;
    long long ok = 0, ng = INF+1;
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    if(ok != INF) cout << ok << endl;
    else cout << "infinite" << endl;
}