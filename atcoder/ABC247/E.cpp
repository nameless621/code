#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Max Min
//    https://atcoder.jp/contests/abc247/tasks/abc247_e



int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> x, y, ng;
    for(int i = 0; i < N; i++) {
        if(A[i] == X) x.push_back(i);
        if(A[i] == Y) y.push_back(i);
        if(A[i] < Y || X < A[i]) ng.push_back(i);
    }

    x.push_back(N);
    y.push_back(N);
    ng.push_back(N);

    long long ans = 0;
    for(int L = 0; L < N; L++) {
        if(A[L] < Y || X < A[L]) continue;
        int res1 = *lower_bound(x.begin(), x.end(), L);
        int res2 = *lower_bound(y.begin(), y.end(), L);
        int res3 = *lower_bound(ng.begin(), ng.end(), L);
        if(res1 == N || res2 == N) break;
        if(res3 < res1 || res3 < res2) continue;
        int R = max(res1, res2);
        ans += res3 - R;
    }

    cout << ans << endl;
}