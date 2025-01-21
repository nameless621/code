#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Robot Takahashi 
//    https://atcoder.jp/contests/abc257/tasks/abc257_c



int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<pair<int, int>> P;
    int x = 0, y = 0;
    for(int i = 0; i < N; i++) {
        int W;
        cin >> W;
        if(S[i] == '0') P.emplace_back(W, 1);
        else {
            P.emplace_back(W, 0);
            x++;
        }
    }

    sort(P.begin(), P.end());
    int ans = x;
    for(int i = 0; i < N; i++) {
        auto[W, t] = P[i];
        if(t == 0) x--;
        else y++;
        ans = max(ans, x + y);
    }

    cout << ans << endl;
}
