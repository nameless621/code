#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Stamp
//    https://atcoder.jp/contests/abc329/tasks/abc329_e



int main() {
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    string str = string(M, '#');
    queue<int> q;
    auto push = [&](int idx) {
        for(int i = max(0, idx - M); i < min(N - M + 1, idx + M); i++) {
            if(S.substr(i, M) == str) continue;
            bool flag = true;
            for(int j = i; j < i + M; j++) {
                if(S[j] != '#' && S[j] != T[j-i]) flag = false;
            }
            if(flag) {
                q.push(i);
                for(int j = i; j < i + M; j++) {
                    S[j] = '#';
                }
            }
        }
    };

    for(int i = 0; i < N - M + 1; i++) {
        push(i);
    }

    while(q.size()) {
        int p = q.front();
        q.pop();
        push(p);
    }

    bool ok = (S == string(N, '#'));
    cout << (ok ? "Yes" : "No") << endl;
}