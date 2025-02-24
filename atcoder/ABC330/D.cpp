#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Counting Ls
//    https://atcoder.jp/contests/abc330/tasks/abc330_d



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'o') {
                x[i]++;
                y[j]++;
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'o') {
                ans += (x[i]-1) * (y[j]-1);
            }
        }
    }

    cout << ans << endl;
}