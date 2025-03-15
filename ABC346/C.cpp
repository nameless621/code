#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Σ
//    https://atcoder.jp/contests/abc346/tasks/abc346_c



int main() {
    int N, K;
    cin >> N >> K;

    set<int> st;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        st.insert(A);
    }

    long long ans = (long long)K * (K + 1) / 2;
    for(int A : st) if(A <= K) ans -= A;
    cout << ans << endl;
}