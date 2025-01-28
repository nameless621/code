#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Postal Card
//    https://atcoder.jp/contests/abc287/tasks/abc287_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N), T(M);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < M; i++) cin >> T[i];

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(find(T.begin(), T.end(), S[i].substr(3, 3)) != T.end()) ans++;
    }

    cout << ans << endl;
}