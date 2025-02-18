#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Round-Robin Tournament
//    https://atcoder.jp/contests/abc323/tasks/abc323_b



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<pair<int, int>> res;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'o') cnt++;
        }
        res.emplace_back(cnt, i);
    }

    sort(res.begin(), res.end(), [&](pair<int, int>& A, pair<int, int>& B) {
        if(A.first != B.first) return A.first > B.first;
        else return A.second < B.second;
    });

    for(int i = 0; i < N; i++) {
        cout << res[i].second + 1 << (i < N - 1 ? " " : "\n");
    }
}