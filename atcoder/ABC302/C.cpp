#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};


//    C - Almost Equal
//    https://atcoder.jp/contests/abc302/tasks/abc302_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<int> pos(N);
    iota(pos.begin(), pos.end(), 0);

    bool ok = false;
    do {
        bool res = true;
        for(int i = 0; i < N - 1; i++) {
            int cnt = 0;
            for(int j = 0; j < M; j++) {
                if(S[pos[i]][j] != S[pos[i+1]][j]) cnt++;
            }
            if(cnt != 1) res = false;
        }
        if(res) ok = true;
    } while(next_permutation(pos.begin(), pos.end()));

    cout << (ok ? "Yes" : "No") << endl;
}