#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Writing a Numeral
//    https://atcoder.jp/contests/abc298/tasks/abc298_d



int main() {
    int Q;
    cin >> Q;

    mint res = 1;
    deque<int> d;
    d.push_back(1);
    while(Q--) {
        int T, x;
        cin >> T;
        if(T == 1) {
            cin >> x;
            res = res * 10 + x;
            d.push_back(x);
        }
        if(T == 2) {
            int num = d.front();
            res -= mint(num) * mint(10).pow(d.size() - 1);
            d.pop_front();
        }
        if(T == 3) {
            cout << res.val() << endl;
        }
    }
}