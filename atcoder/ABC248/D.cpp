#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Range Count Query
//    https://atcoder.jp/contests/abc248/tasks/abc248_d



int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> dict(N+1);
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        dict[A].push_back(i);
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int L, R, X;
        cin >> L >> R >> X;
        L--; R--;
        int l = lower_bound(dict[X].begin(), dict[X].end(), L) - dict[X].begin();
        int r = upper_bound(dict[X].begin(), dict[X].end(), R) - dict[X].begin();
        cout << r - l << endl;
    }
}