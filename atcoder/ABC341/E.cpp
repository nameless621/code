#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Alternating String 
//    https://atcoder.jp/contests/abc341/tasks/abc341_e



int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    set<int> st;
    st.insert(N+1);
    for(int i = 0; i < N-1; i++) {
        if(S[i] == S[i+1]) st.insert(i+1);
    }

    while(Q--) {
        int t, L, R;
        cin >> t >> L >> R;
        L--;
        if(t == 1) {
            if(st.count(L)) st.erase(L);
            else st.insert(L);
            if(st.count(R)) st.erase(R);
            else st.insert(R);
        }
        if(t == 2) {
            int res = *st.upper_bound(L);
            cout << (res >= R ? "Yes" : "No") << '\n';
        }
    }
}