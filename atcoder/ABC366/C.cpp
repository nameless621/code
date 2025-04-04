#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Balls and Bag Query
//    https://atcoder.jp/contests/abc366/tasks/abc366_c



int main() {
    int Q;
    cin >> Q;

    map<int, int> cnt;
    while(Q--) {
        int op, x;
        cin >> op;
        if(op == 1) {
            cin >> x;
            cnt[x]++;
        }
        if(op == 2) {
            cin >> x;
            cnt[x]--;
            if(cnt[x] == 0) cnt.erase(x);
        }
        if(op == 3) {
            cout << cnt.size() << endl;
        }
    }
}