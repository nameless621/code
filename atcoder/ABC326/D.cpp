#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - ABC Puzzle
//    https://atcoder.jp/contests/abc326/tasks/abc326_d



int main() {
    int N;
    string R, C;
    cin >> N >> R >> C;

    string T = "ABC";
    while((int)T.size() < N) T += '.';
    sort(T.begin(), T.end());

    vector<string> S;
    do {
        S.push_back(T);
    } while(next_permutation(T.begin(), T.end()));


    vector<string> res, ans;
    vector<bool> used(S.size());
    auto dfs = [&](auto dfs, int now) -> void {
        if(ans.size()) return;

        res.push_back(S[now]);
        used[now] = true;

        if((int)res.size() == N) {
            string x, y;
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(res[i][j] != '.') {
                        x += res[i][j];
                        break;
                    }
                }
            }
            for(int j = 0; j < N; j++) {
                for(int i = 0; i < N; i++) {
                    if(res[i][j] != '.') {
                        y += res[i][j];
                        break;
                    }
                }
            }

            if(x == R && y == C) {
                ans = res;
            }

            res.pop_back();
            used[now] = false;
            return;
        }
        
        vector<vector<bool>> ok(N, vector<bool>(3));
        for(int i = 0; i < (int)res.size(); i++) {
            for(int j = 0; j < N; j++) {
                if(res[i][j] == '.') continue;
                ok[j][res[i][j] - 'A'] = true;
            }
        }

        for(int i = 0; i < (int)S.size(); i++) {
            if(used[i]) continue;
            bool flag = true;
            for(int j = 0; j < N; j++) {
                if(S[i][j] == '.') continue;
                if(ok[j][S[i][j] - 'A']) flag = false;
            }
            if(flag) dfs(dfs, i);
        }

        res.pop_back();
        used[now] = false;
    };

    for(int i = 0; i < (int)S.size(); i++) {
        dfs(dfs, i);
    }

    if(ans.size()) {
        cout << "Yes" << endl;
        for(int i = 0; i < N; i++) {
            cout << ans[i] << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}