#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Repunit Trio
//    https://atcoder.jp/contests/abc333/tasks/abc333_c



int main() {
    vector<long long> R;
    long long x = 1;
    while(x < 1e18) {
        R.push_back(x);
        x = x * 10 + 1;
    }

    vector<long long> res;
    int len = R.size();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < len; k++) {
                res.push_back(R[i] + R[j] + R[k]);
            }
        }
    }

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    int N;
    cin >> N;
    cout << res[N-1] << endl;
}