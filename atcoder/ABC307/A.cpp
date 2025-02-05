#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Weekly Records
//    https://atcoder.jp/contests/abc307/tasks/abc307_a



int main() {
    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        int res = 0;
        for(int j = 0; j < 7; j++) {
            int A;
            cin >> A;
            res += A;
        }
        cout << res << endl;
    }
}