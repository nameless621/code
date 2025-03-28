#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Move It 
//    https://atcoder.jp/contests/abc360/tasks/abc360_c



int main() {
    int N;
    cin >> N;

    vector<int> A(N), W(N);
    for(int& a : A) cin >> a;
    for(int& w : W) cin >> w;

    vector<vector<int>> box(N);
    for(int i = 0; i < N; i++) {
        A[i]--;
        box[A[i]].push_back(W[i]);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        sort(box[i].begin(), box[i].end());
        for(int j = 0; j < (int)box[i].size()-1; j++) {
            ans += box[i][j];
        }
    }

    cout << ans << endl;
}