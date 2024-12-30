#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Sequence Query 
//    https://atcoder.jp/contests/abc241/tasks/abc241_d



int main() {
    int Q;
    cin >> Q;

    multiset<long long> A;
    while(Q--) {
        int T, k;
        long long x;
        cin >> T;

        if(T == 1) {
            cin >> x;
            A.insert(x);
        }
        if(T == 2) {
            cin >> x >> k;
            auto itr = A.upper_bound(x);
            bool ok = true;
            for(int i = 0; i < k; i++) {
                if(itr == A.begin()) {
                    ok = false;
                    break;
                }
                itr--;
            }
            cout << (ok ? *itr : -1) << endl;
        }
        if(T == 3) {
            cin >> x >> k;
            auto itr = A.lower_bound(x);
            bool ok = true;
            for(int i = 0; i < k - 1; i++) {
                if(itr == A.end()) {
                    ok = false;
                    break;
                }
                itr++;
            }
            cout << ((ok && itr != A.end()) ? *itr : -1) << endl;
        }
    }
}