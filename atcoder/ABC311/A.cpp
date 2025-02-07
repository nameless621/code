#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - First ABC
//    https://atcoder.jp/contests/abc311/tasks/abc311_a



int main() {
    int N;
    string S;
    cin >> N >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int x = S[i] - 'A';
        if(x > 2) continue;
        cnt |= 1 << x;
        if(cnt == (1 << 3) - 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}