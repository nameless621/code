#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Tetrahedral Number
//    https://atcoder.jp/contests/abc335/tasks/abc335_b



int main() {
    int N;
    cin >> N;

    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = 0; k <= N; k++) {
                if(i + j + k <= N) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}