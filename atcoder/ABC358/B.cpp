#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Ticket Counter
//    https://atcoder.jp/contests/abc358/tasks/abc358_b



int main() {
    int N, A;
    cin >> N >> A;

    vector<int> T(N);
    for(int& t : T) cin >> t;

    int now = 0;
    for(int i = 0; i < N; i++) {
        now = max(now, T[i]) + A;
        cout << now << endl;
    }
}