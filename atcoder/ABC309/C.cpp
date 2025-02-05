#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Medicine 
//    https://atcoder.jp/contests/abc309/tasks/abc309_c



int main() {
    int N, K;
    cin >> N >> K;

    long long sum = 0;
    vector<pair<int, int>> M(N);
    for(int i = 0; i < N; i++) {
        cin >> M[i].first >> M[i].second;
        sum += M[i].second;
    }

    sort(M.begin(), M.end());

    if(sum <= K) {
        cout << 1 << endl;
        return 0;
    }

    for(auto[a, b] : M) {
        sum -= b;
        if(sum <= K) {
            cout << a + 1 << endl;
            return 0;
        }
    }
}