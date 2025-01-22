#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Ancestor
//    https://atcoder.jp/contests/abc263/tasks/abc263_b



int main() {
    int N;
    cin >> N;
    
    vector<int> P(N, -1);
    for(int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    int ans = 0, now = N - 1;
    while(now != 0) {
        ans++;
        now = P[now];
    }

    cout << ans << endl;
}