#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - AtCoder Amusement Park 
//    https://atcoder.jp/contests/abc353/tasks/abc353_b



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int& a : A) cin >> a;

    int cnt = 0, now = 0;
    for(int i = 0; i < N; i++) {
        if(now + A[i] <= K) {
            now += A[i];
        }
        else {
            cnt++;
            now = A[i];
        }
    }

    if(now > 0) cnt++;
    cout << cnt << endl;
}