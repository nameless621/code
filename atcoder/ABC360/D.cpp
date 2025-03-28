#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Ghost Ants
//    https://atcoder.jp/contests/abc360/tasks/abc360_d



int main() {
    int N, T;
    string S;
    cin >> N >> T >> S;

    vector<long> L, R;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if(S[i] == '0') L.push_back(X);
        else R.push_back(X); 
    }

    sort(L.begin(), L.end());

    long long ans = 0;
    for(long p : R) {
        int x = lower_bound(L.begin(), L.end(), p) - L.begin();
        int y = upper_bound(L.begin(), L.end(), p + T * 2) - L.begin();
        ans += y - x;
    }

    cout << ans << endl;
}