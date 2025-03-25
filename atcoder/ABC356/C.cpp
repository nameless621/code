#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Keys
//    https://atcoder.jp/contests/abc356/tasks/abc356_c



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> C(M);
    vector<char> R(M);
    vector<vector<int>> A(M);
    for(int i = 0; i < M; i++) {
        cin >> C[i];
        A[i].resize(C[i]);
        for(int j = 0; j < C[i]; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
        cin >> R[i];
    }

    int ans = 0;
    for(int S = 0; S < (1 << N); S++) {
        bool ok = true;
        for(int i = 0; i < M; i++) {
            int cnt = 0;
            for(int j = 0; j < C[i]; j++) {
                if(S >> A[i][j] & 1) cnt++;
            }
            if(R[i] == 'o' && cnt < K) ok = false;
            if(R[i] == 'x' && cnt >= K ) ok = false;
        }
        if(ok) ans++;
    }

    cout << ans << endl;
}