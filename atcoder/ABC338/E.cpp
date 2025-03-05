#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Chords
//    https://atcoder.jp/contests/abc338/tasks/abc338_e



int main() {
    int N;
    cin >> N;

    vector<tuple<int, int, int>> P;
    for(int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        if(A > B) swap(A, B);
        P.emplace_back(A, i, 0);
        P.emplace_back(B, i, 1);
    }

    sort(P.begin(), P.end());

    int M = P.size();
    bool res = false;
    stack<tuple<int, int, int>> st;
    for(int i = 0; i < M; i++) {
        if(st.empty()) {
            st.emplace(P[i]);
            continue;
        }
        auto[pos1, idx1, t1] = P[i];
        auto[pos2, idx2, t2] = st.top();
        if(idx1 == idx2) st.pop();
        else if(t1 != t2) {
            res = true;
            break;
        }
        else st.push(P[i]);
    }

    cout << (res ? "Yes" : "No") << endl;
}