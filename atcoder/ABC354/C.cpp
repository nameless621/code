#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - AtCoder Magics
//    https://atcoder.jp/contests/abc354/tasks/abc354_c



int main() {
    int N;
    cin >> N;

    vector<tuple<int, int, int>> T(N);
    for(int i = 0; i < N; i++) {
        int A, C;
        cin >> A >> C;
        T.emplace_back(A, C, i);
    }

    sort(T.rbegin(), T.rend());
    int now = 2e9;
    vector<int> res;
    for(int i = 0; i < N; i++) {
        auto[A, C, idx] = T[i];
        if(C <= now) {
            res.push_back(idx + 1);
            now = C;
        }
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(int num : res) cout << num << " ";
    cout << endl;
}