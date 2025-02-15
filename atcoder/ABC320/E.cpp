#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Somen Nagashi
//    https://atcoder.jp/contests/abc320/tasks/abc320_e



using T = tuple<int, int, int>;

int main() {
    int N, M;
    cin >> N >> M;

    set<int> st;
    for(int i = 0; i < N; i++) {
        st.insert(i);
    }

    vector<long long> sum(N);
    priority_queue<T, vector<T>, greater<T>> pq;
    for(int i = 0; i < M; i++) {
        int T, W, S;
        cin >> T >> W >> S;
        pq.emplace(T, W, S);
    }

    while(!pq.empty()) {
        auto[T, W, S] = pq.top();
        pq.pop();
        if(W == -1) {
            st.insert(S);
            continue;
        }
        if(st.empty()) continue;
        int idx = *st.begin();
        st.erase(st.begin());
        sum[idx] += W;
        pq.emplace(T + S, -1, idx);
    }

    for(int i = 0; i < N; i++) {
        cout << sum[i] << endl;
    }
}