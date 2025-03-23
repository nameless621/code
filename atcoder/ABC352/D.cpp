#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Permutation Subsequence
//    https://atcoder.jp/contests/abc352/tasks/abc352_d



int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i].first;
        P[i].second = i;
    }

    sort(P.begin(), P.end());

    int ans = 1e9;
    set<int> st;
    for(int i = 0; i < N; i++) {
        st.insert(P[i].second);
        if((int)st.size() == K) {
            ans = min(ans, *prev(st.end()) - *st.begin());
            st.erase(P[i-K+1].second);
        }
    }

    cout << ans << endl;
}