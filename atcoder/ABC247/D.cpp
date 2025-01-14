#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Cylinder
//    https://atcoder.jp/contests/abc247/tasks/abc247_d



int main() {
    int Q;
    cin >> Q;

    deque<pair<long long, long long>> dq;
    while(Q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x, c;
            cin >> x >> c;
            dq.push_front({x, c});
        }
        else {
            int c;
            cin >> c;
            long long res = 0;
            while(c) {
                auto[num, cnt] = dq.back();
                if(cnt <= c) {
                    res += num * cnt;
                    c -= cnt;
                    dq.pop_back();
                }
                else {
                    res += num * c;
                    dq.back().second -= c;
                    break;
                }
            }
            cout << res << endl;
        }
    }
}