#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - 青木君のいたずら
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_e



int main() {
    long long N;
    cin >> N;

    int ans = -1;
    for(int k = 1; k <= 30; k++) {
        long long X = 1;
        for(int cnt = 1; cnt <= 30; cnt++) {
            X *= 3;
            if(cnt == k) X++;
        }
        if(X == N) ans = k;
    }

    cout << ans << endl;
}