#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - 321-like Searcher
//    https://atcoder.jp/contests/abc321/tasks/abc321_c



int main() {
    int N = 1 << 10;
    vector<long long> res;
    for(int bit = 0; bit < N; bit++) {
        long long temp = 0;
        for(int i = 9; i >= 0; i--) {
            if(bit >> i & 1) {
                temp = temp * 10 + i;
            }
        }
        if(temp > 0) res.push_back(temp);
    }
    sort(res.begin(), res.end());

    int K;
    cin >> K;
    cout << res[K-1] << endl;
}