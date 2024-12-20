#include <bits/stdc++.h>
using namespace std;


//    D - Destroyer Takahashi
//    https://atcoder.jp/contests/abc230/tasks/abc230_d



int main() {
    int N, D;
    cin >> N >> D;
    
    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].second >> P[i].first;
    }

    sort(P.begin(), P.end());

    int ans = 0;
    for(int i = 0; i < N; i++) {
        auto[R, L] = P[i];
        int X = R + D - 1;
        while(i + 1 < N && P[i + 1].second <= X) i++;
        ans++;
    }

    cout << ans << endl;
}