#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - The Kth Time Query 
//    https://atcoder.jp/contests/abc235/tasks/abc235_c



int main() {
    int N, Q;
    cin >> N >> Q;

    map<int, vector<int>> M;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        M[A].push_back(i + 1);
    }

    while(Q--) {
        int x, k;
        cin >> x >> k;
        int ans = -1;
        if(M.count(x) && (int)M[x].size() >= k) {
            ans = M[x][k - 1];
        }
        cout << ans << endl;
    }
}