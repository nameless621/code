#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Japanese Cursed Doll
//    https://atcoder.jp/contests/abc363/tasks/abc363_b



int main() {
    int N, T, P;
    cin >> N >> T >> P;

    vector<int> L(N);
    for(int& l : L) cin >> l;

    int ans = 0;
    for(;;ans++) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(L[i] + ans >= T) cnt++;
        }
        if(cnt >= P) break;
    }

    cout << ans << endl;
}