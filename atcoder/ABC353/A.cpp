#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Buildings
//    https://atcoder.jp/contests/abc353/tasks/abc353_a



int main() {
    int N;
    cin >> N;

    vector<int> H(N);
    for(int&h : H) cin >> h;

    int ans = -1;
    for(int i = 1; i < N; i++) {
        if(H[0] < H[i]) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
}