#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Cutting Woods
//    https://atcoder.jp/contests/abc217/tasks/abc217_d



int main() {
    int L, Q;
    cin >> L >> Q;
    
    set<int> s;
    s.insert(0);
    s.insert(L);
    
    while(Q--) {
        int c, x;
        cin >> c >> x;
        if(c == 1) {
            s.insert(x);
        }
        else {
            auto itr = s.lower_bound(x);
            int r = *itr;
            itr--;
            int l = *itr;
            cout << r - l << endl;
        }
    }
}