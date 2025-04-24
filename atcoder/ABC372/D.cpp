#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Buildings
//    https://atcoder.jp/contests/abc372/tasks/abc372_d



int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int& h : H) cin >> h;

    vector<int> ans(N);
    stack<int> st;
    for(int i = N-1; i >= 0; i--) {
        ans[i] = st.size();
        while(!st.empty() && st.top() < H[i]) st.pop();
        st.push(H[i]);
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << (i < N-1 ? " " : "\n");
    }
}