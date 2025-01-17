#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Max - Min Query
//    https://atcoder.jp/contests/abc253/tasks/abc253_c



int main() {
    int Q;
    cin >> Q;

    map<int, long long> S;
    while(Q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            S[x]++;
        }
        if(t == 2) {
            int x, c;
            cin >> x >> c;
            S[x] -= c;
            if(S[x] <= 0) S.erase(x);
        }
        if(t == 3) {
            auto[k1, v1] = *S.begin();
            auto[k2, v2] = *S.rbegin();
            cout << k2 - k1 << endl;
        }
    }
}