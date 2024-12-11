#include <bits/stdc++.h>
using namespace std;


//    D - Project Planning
//    https://atcoder.jp/contests/abc227/tasks/abc227_d



int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto f = [&](long long X) {
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            sum += min(A[i], X);
        }
        return sum >= X * K;
    };

    long long OK = 0, NG = 1e18 / K;
    while(abs(OK - NG) > 1) {
        long long mid = (OK + NG) / 2;
        if(f(mid)) OK = mid;
        else NG = mid;
    }

    cout << OK << endl;
}