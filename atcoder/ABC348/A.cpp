#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Penalty Kick
//    https://atcoder.jp/contests/abc348/tasks/abc348_a



int main() {
    int N;
    cin >> N;

    string res;
    for(int i = 1; i <= N; i++) {
        if(i % 3) res += 'o';
        else res += 'x';
    }

    cout << res << endl;
}