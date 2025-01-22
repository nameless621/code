#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Iroha and Haiku (New ABC Edition)
//    https://atcoder.jp/contests/abc265/tasks/abc265_d



int main() {
    int N;
    long long P, Q, R;
    cin >> N >> P >> Q >> R;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<long long> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    bool ok = false;
    for(int x = 0; x < N; x++) {
        int y = lower_bound(S.begin()+x, S.end(), P + S[x]) - S.begin();
        if(y == N || S[y] - S[x] != P) continue;
        int z = lower_bound(S.begin()+y+1, S.end(), Q + S[y]) - S.begin();
        if(z == N || S[z] - S[y] != Q) continue;
        int w = lower_bound(S.begin()+z+1, S.end(), R + S[z]) - S.begin();
        if(w == N+1 || S[w] - S[z] != R) continue;
        ok = true;
        break;
    }

    cout << (ok ? "Yes" : "No") << endl;
}