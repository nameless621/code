#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Broken Rounding
//    https://atcoder.jp/contests/abc273/tasks/abc273_b



int main() {
    long long X;
    int K;
    cin >> X >> K;
    for(int i = 0; i < K; i++) {
        long long p = pow(10, i);
        int y = (X / p) % 10;
        X -= X % (p * 10);
        if(y >= 5) X += p * 10;
    }
    cout << X << endl;
}