#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Minimum Glutton
//    https://atcoder.jp/contests/abc364/tasks/abc364_c



int main() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N), B(N);
    for(int& a : A) cin >> a;
    for(int& b : B) cin >> b;

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    auto f = [&](vector<int> x, long long limit) {
        int ret = -1;
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            sum += x[i];
            ret = i + 1;
            if(sum > limit) break;
        }
        return ret;
    };

    int a = f(A, X);
    int b = f(B, Y);
    cout << min(a, b) << endl;
}