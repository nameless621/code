#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - LEQ
//    https://atcoder.jp/contests/abc221/tasks/abc221_e



using mint = modint998244353;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    auto B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    vector<int> res(N);
    for(int i = 0; i < N; i++) {
        int idx = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        res[i] = idx;
    }

    fenwick_tree<mint> ft(N + 1);
    mint ans = 0, two = 1, itwo = 1;
    for(int i = 0; i < N; i++) {
        ans += two * ft.sum(0, res[i] + 1);
        two *= 2; itwo /= 2;
        ft.add(res[i], itwo);
    }

    cout << ans.val() << endl;
}