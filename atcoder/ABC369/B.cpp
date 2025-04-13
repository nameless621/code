#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Piano 3
//    https://atcoder.jp/contests/abc369/tasks/abc369_b



int main() {
    int N;
    cin >> N;

    int l = -1, r = -1;
    vector<int> A(N);
    vector<char> S(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> S[i];
        if(S[i] == 'L' && l == -1) l = A[i];
        if(S[i] == 'R' && r == -1) r = A[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'L') {
            ans += abs(l - A[i]);
            l = A[i];
        }
        if(S[i] == 'R') {
            ans += abs(r - A[i]);
            r = A[i];
        }
    }

    cout << ans << endl;
}