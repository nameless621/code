#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Loong Tracking
//    https://atcoder.jp/contests/abc335/tasks/abc335_c



int main() {
    int N, Q;
    cin >> N >> Q;

    deque<pair<int, int>> d;
    for(int i = 0; i < N; i++) {
        d.emplace_back(i+1, 0);
    }

    while(Q--) {
        int T;
        cin >> T;
        if(T == 1) {
            char C;
            cin >> C;
            auto[x, y] = d.front();
            if(C == 'R') x++;
            if(C == 'L') x--;
            if(C == 'U') y++;
            if(C == 'D') y--;
            d.push_front({x, y});
        }
        if(T == 2) {
            int p;
            cin >> p;
            auto[x, y] = d[p-1];
            cout << x << " " << y << endl;
        }
    }
}