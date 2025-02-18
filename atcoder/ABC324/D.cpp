#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Square Permutation
//    https://atcoder.jp/contests/abc324/tasks/abc324_d



int main() {
    int N;
    string S;
    cin >> N >> S;

    sort(S.rbegin(), S.rend());
    long long M = stoll(S);

    int ans = 0;
    for(long long p = 0; p * p <= M; p++) {
        long long X = p * p;
        string T = to_string(X);
        sort(T.rbegin(), T.rend());
        while((int)T.size() < N) T += '0';
        if(S == T) ans++;
    }

    cout << ans << endl;
}