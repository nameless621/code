#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Reversible
//    https://atcoder.jp/contests/abc310/tasks/abc310_c



int main() {
    int N;
    cin >> N;

    set<string> st;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if(st.count(S)) continue;
        reverse(S.begin(), S.end());
        if(st.count(S)) continue;
        st.insert(S);
    }

    cout << st.size() << endl;
}