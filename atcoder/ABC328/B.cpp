#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - 11/11 
//    https://atcoder.jp/contests/abc328/tasks/abc328_b



int main() {
    int N;
    cin >> N;

    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int x = i + 1;
        if(x >= 10 && x / 10 != x % 10) continue;
        if(x == 100) continue;
        for(int j = 1; j <= min(99, D[i]); j++) {
            if(j >= 10 && j / 10 != j % 10) continue;
            if(x % 10 == j % 10) ans++; 
        }
    }

    cout << ans << endl;
}