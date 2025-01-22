#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Monotonically Increasing
//    https://atcoder.jp/contests/abc263/tasks/abc263_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> ans;
    auto dfs = [&](auto dfs, vector<int> now, int st) -> void {
        if((int)now.size() == N) {
            ans.push_back(now);
            return;
        }
        for(int i = st; i <= M; i++) {
            now.push_back(i);
            dfs(dfs, now, i+1);
            now.pop_back();
        }
    };

    dfs(dfs, {}, 1);
    
    for(auto vec : ans) {
        for(int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}