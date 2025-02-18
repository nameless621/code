#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Same
//    https://atcoder.jp/contests/abc324/tasks/abc324_a



int main() {
    int N;
    cin >> N;

    set<int> st;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        st.insert(A);
    }

    cout << ((int)st.size() == 1 ? "Yes" : "No") << endl;
}