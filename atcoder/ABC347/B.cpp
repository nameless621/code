#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Substring
//    https://atcoder.jp/contests/abc347/tasks/abc347_b



int main() {
    string S;
    cin >> S;

    int N = S.size();
    set<string> st;
    for(int i = 0; i < N; i++) {
        for(int j = 1; i+j <= N; j++) {
            st.insert(S.substr(i, j));
        }
    }

    cout << st.size() << endl;
}