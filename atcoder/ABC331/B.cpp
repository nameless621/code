#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Buy One Carton of Milk
//    https://atcoder.jp/contests/abc331/tasks/abc331_b



int main() {
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    int ans = 1e9;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            for(int k = 0; k < 100; k++) {
                if(6*i + 8*j + 12*k >= N) {
                    ans = min(ans, S*i + M*j + L*k);
                }
            }
        }
    }

    cout << ans << endl;
}