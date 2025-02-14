#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Sandwiches
//    https://atcoder.jp/contests/abc318/tasks/abc318_e



int main() {
    int N;
    cin >> N;
    unordered_map<int, vector<int>> M;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        M[A].push_back(i);
    }

    long long ans = 0;
    for(auto[k, vec] : M) {
        int len = vec.size();
        for(int i = 0; i < len - 1; i++) {
            ans += (long long)(vec[i+1] - vec[i] - 1) * (i + 1) * (len - i - 1);
        }
    }

    cout << ans << endl;
}