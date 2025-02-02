#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Subscribers
//    https://atcoder.jp/contests/abc304/tasks/abc304_b



int main() {
    int N;
    cin >> N;
    
    if(1e3 <= N) N -= N % 10;
    if(1e4 <= N) N -= N % 100;
    if(1e5 <= N) N -= N % 1000;
    if(1e6 <= N) N -= N % 10000;
    if(1e7 <= N) N -= N % 100000;
    if(1e8 <= N) N -= N % 1000000;

    cout << N << endl;
}