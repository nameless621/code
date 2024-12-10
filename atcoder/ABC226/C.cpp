#include <bits/stdc++.h>
using namespace std;


//        C - Martial artist
//        https://atcoder.jp/contests/abc226/tasks/abc226_c



int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    vector<vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int K;
        cin >> T[i] >> K;
        A[i].resize(K);
        for(int j = 0; j < K; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    long long ans = T[N - 1];
    vector<bool> ok(N);
    ok[N - 1] = true;
    for(int i = N - 1; i >= 0; i--) {
        if(ok[i] == false) continue;
        for(int j : A[i]) {
            if(ok[j] == true) continue;
            ok[j] = true;
            ans += T[j];
        }
    }

    cout << ans << endl;
}