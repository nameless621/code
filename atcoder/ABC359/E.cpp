#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Water Tank 
//    https://atcoder.jp/contests/abc359/tasks/abc359_e



int main() {
    int N;
    cin >> N;

    vector<long long> H(N);
    for(long long& h : H) cin >> h;

    long long now = 0;
    stack<pair<long long, long long>> st;
    for(int i = 0; i < N; i++) {
        int cnt = 1;
        while(!st.empty() && st.top().first < H[i]) {
            cnt += st.top().second;
            now -= st.top().first * st.top().second;
            st.pop();
        }
        now += H[i] * cnt;
        cout << now + 1 << " ";
        st.emplace(H[i], cnt);
    }

    cout << endl;
}