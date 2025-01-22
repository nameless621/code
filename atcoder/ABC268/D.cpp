#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Unique Username
//    https://atcoder.jp/contests/abc268/tasks/abc268_d



int main() {
    int N, M;
    cin >> N >> M;

    int len = 0;
    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
        len += S[i].size();
    } 

    set<string> T;
    for(int i = 0; i < M; i++) {
        string t;
        cin >> t;
        T.insert(t);
    }

    string X = "-1";
    vector<int> pos(N);
    iota(pos.begin(), pos.end(), 0);

    auto dfs = [&](auto dfs, string now, int idx, int rem) -> void {
        if(X != "-1") return;

        now += S[pos[idx]];
        rem -= S[pos[idx]].size();

        if(idx == N-1) {
            if((int)now.size() >= 3 && !T.count(now)) X = now;
            return;
        }

        while((int)now.size() + 1 + rem <= 16) {
            now += "_";
            dfs(dfs, now, idx + 1, rem);
        }
    };


    do {
        dfs(dfs, "", 0, len);
    } while(next_permutation(pos.begin(), pos.end()));

    cout << X << endl;
}