#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - 326-like Numbers 
//    https://atcoder.jp/contests/abc326/tasks/abc326_b



int main() {
    int N;
    cin >> N;

    for(int i = N; i < 1000; i++) {
        int x = i / 100;
        int y = (i / 10) % 10;
        int z = i % 10;
        if(x * y == z) {
            cout << i << endl;
            return 0;
        }
    }
}