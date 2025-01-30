#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - M<=ab
//    https://atcoder.jp/contests/abc296/tasks/abc296_d



int main() {
    long long N, M;
    cin >> N >> M;
    
    if((M + N - 1) / N > N) {
        cout << -1 << endl;
        return 0;
    }

    long long X = LLONG_MAX;
    for(long long A = 1; A <= N; A++) {
        long long B = (M + A - 1) / A;
        if(B <= N) X = min(X, A * B);
        if(A > B) break;
    }

    cout << X << endl;
}