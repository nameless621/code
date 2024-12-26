#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - カラフルなTシャツ
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_e



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> C(N), P(N);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> P[i];

    map<int, int> T;
    for(int i = 0; i < N; i++) {
        if(T.count(C[i])) T[C[i]] = min(T[C[i]], P[i]);
        else T[C[i]] = P[i];
    }

    if((int)T.size() < K) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> vec;
    for(auto[key, value] : T) {
        vec.push_back(value);
    }

    sort(vec.begin(), vec.end());
    long long ans = 0;
    for(int i = 0; i < K; i++) {
        ans += vec[i];
    }

    cout << ans << endl;
}