#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Merge Slimes
//    https://atcoder.jp/contests/abc323/tasks/abc323_d



int main() {
    int N;
    cin >> N;

    map<long long, long long> Slimes;
    for(int i = 0; i < N; i++) {
        int S, C;
        cin >> S >> C;
        Slimes[S] += C;
    }

    long long ans = 0;
    while(!Slimes.empty()) {
        auto[S, C] = *Slimes.begin();
        Slimes.erase(S);
        if(C & 1) ans++;
        if(C > 1) Slimes[S * 2] += C / 2;
    }

    cout << ans << endl;
}