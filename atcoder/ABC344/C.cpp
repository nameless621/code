#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - A+B+C
//    https://atcoder.jp/contests/abc344/tasks/abc344_c



vector<int> read(int N) {
    vector<int> res(N);
    for(int i = 0; i < N; i++) cin >> res[i];
    return res;
}

int main() {
    int N;
    cin >> N;
    auto A = read(N);

    int M;
    cin >> M;
    auto B = read(M);

    int L;
    cin >> L;
    auto C = read(L);

    set<int> st;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < L; k++) {
                st.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int X;
        cin >> X;
        cout << (st.count(X) ? "Yes" : "No") << '\n';
    }
}