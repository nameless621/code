#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Sanitize Hands
//    https://atcoder.jp/contests/abc357/tasks/abc357_a



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> H(N);
    for(int& h : H) cin >> h;

    for(int i = 0; i < N; i++) {
        M -= H[i];
        if(M < 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << N << endl;
}