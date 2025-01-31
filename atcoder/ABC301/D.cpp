#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Bitmask
//    https://atcoder.jp/contests/abc301/tasks/abc301_d



int main() {
    string S;
    long long N;
    cin >> S >> N;

    long long T = 0;
    reverse(S.begin(), S.end());
    for(int i = 0; i < (int)S.size(); i++) {
        if(S[i] == '1') T |= 1ll << i;
    }

    if(T > N) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = (int)S.size() - 1; i >= 0; i--) {
        if(S[i] == '?' && (T | (1ll << i)) <= N) T |= 1ll << i;
    }

    cout << T << endl;
}