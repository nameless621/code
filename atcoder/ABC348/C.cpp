#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Colorful Beans 
//    https://atcoder.jp/contests/abc348/tasks/abc348_c



int main() {
    int N;
    cin >> N;

    map<int, int> beans;
    for(int i = 0; i < N; i++) {
        int A, C;
        cin >> A >> C;
        if(beans.count(C)) beans[C] = min(beans[C], A);
        else beans[C] = A;
    }

    int ans = -1;
    for(auto[k, v] : beans) {
        ans = max(ans, v);
    }

    cout << ans << endl;
}