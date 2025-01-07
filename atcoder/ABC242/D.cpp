#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - ABC Transform
//    https://atcoder.jp/contests/abc242/tasks/abc242_d



int main() {
    string S;
    int Q;
    cin >> S >> Q;

    auto f = [&](char c, long long x) {
        return char('A' + (c - 'A' + x) % 3);
    };
    
    auto rec = [&](auto rec, long long t, long long k) -> char {
        if(t == 0) return S[k];
        if(k == 0) return f(S[0], t);
        return f(rec(rec, t - 1, k / 2), k % 2 + 1);
    };

    while(Q--) {
        long long t, k;
        cin >> t >> k;
        cout << rec(rec, t, k - 1) << endl;
    }
}