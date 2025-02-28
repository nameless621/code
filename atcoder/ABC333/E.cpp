#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Takahashi Quest
//    https://atcoder.jp/contests/abc333/tasks/abc333_e



int main() {
    int N;
    cin >> N;

    vector<int> t(N), x(N);
    for(int i = 0; i < N; i++) {
        cin >> t[i] >> x[i];
        x[i]--;
    }

    int K = 0, P = 0;
    vector<int> res, cnt(N);
    for(int i = N-1; i >= 0; i--) {
        if(t[i] == 1) {
            if(cnt[x[i]] > 0) {
                cnt[x[i]]--;
                P--;
                res.push_back(1);
            }
            else {
                res.push_back(0);
            }
        }
        else {
            P++;
            cnt[x[i]]++;
        }
        K = max(K, P);
    }

    for(int i = 0; i < N; i++) {
        if(cnt[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << K << endl;
    reverse(res.begin(), res.end());
    int M = res.size();
    for(int i = 0; i < M; i++) {
        cout << res[i] << (i == M-1 ? '\n' : ' ');
    }
}