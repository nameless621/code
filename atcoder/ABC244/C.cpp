#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Yamanote Line Game
//    https://atcoder.jp/contests/abc244/tasks/abc244_c



int main() {
    int N;
    cin >> N;
    vector<bool> ok(2 * N + 5);
    while(!ok[0]) {
        for(int i = 1; i <= 2 * N + 1; i++) {
            if(ok[i]) continue;
            ok[i] = true;
            cout << i << endl;
            break;
        }
        int res;
        cin >> res;
        ok[res] = true;
    }
}