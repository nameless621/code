#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Glass and Mug
//    https://atcoder.jp/contests/abc332/tasks/abc332_b



int main() {
    int K, G, M;
    cin >> K >> G >> M;

    int A = 0, B = 0;
    while(K--) {
        if(A == G) {
            A = 0;
        }
        else if(B == 0) {
            B = M;
        }
        else {
            while(A < G && B > 0) {
                A++;
                B--;
            }
        }
    }

    cout << A << " " << B << endl;
}