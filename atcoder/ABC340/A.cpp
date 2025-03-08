#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Arithmetic Progression
//    https://atcoder.jp/contests/abc340/tasks/abc340_a



int main() {
    int A, B, D;
    cin >> A >> B >> D;

    for(int i = A; i <= B; i += D) {
        cout << i << (i < B ? " " : "\n");
    }
}