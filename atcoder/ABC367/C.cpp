#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Enumerate Sequences
//    https://atcoder.jp/contests/abc367/tasks/abc367_c



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> R(N);
    for(int& r : R) cin >> r;

    vector<int> vec;
    vector<vector<int>> ans;
    auto f = [&](auto f, int now, int sum) -> void {
        if(now == N) {
            if(sum % K == 0) ans.push_back(vec);
            return;
        }

        for(int i = 1; i <= R[now]; i++) {
            vec.push_back(i);
            f(f, now + 1, sum + i);
            vec.pop_back();
        }
    };

    f(f, 0, 0);
    for(auto v : ans) {
        for(int num : v) cout << num << " ";
        cout << endl;
    }
}