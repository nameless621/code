#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Roulette
//    https://atcoder.jp/contests/abc314/tasks/abc314_b



int main() {
    int N;
    cin >> N;

    vector<int> C(N);
    vector<vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> C[i];
        A[i].resize(C[i]);
        for(int j = 0; j < C[i]; j++) {
            cin >> A[i][j];
        }
    }

    int X;
    cin >> X;

    int cnt = 40;
    vector<bool> ok(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < C[i]; j++) {
            if(A[i][j] == X) {
                ok[i] = true;
                cnt = min(cnt, C[i]);
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(ok[i] && cnt == C[i]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for(int num : ans) cout << num << " ";
    cout << endl;
}