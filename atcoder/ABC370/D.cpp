#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Cross Explosion
//    https://atcoder.jp/contests/abc370/tasks/abc370_d



int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    vector<set<int>> tate(W), yoko(H);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            tate[j].insert(i);
            yoko[i].insert(j);
        }
    } 

    int INF = 1e9;
    for(int i = 0; i < W; i++) {
        tate[i].insert(-1);
        tate[i].insert(INF);
    }
    for(int i = 0; i < H; i++) {
        yoko[i].insert(-1);
        yoko[i].insert(INF);
    }

    int rem = H * W;
    auto erase = [&](int x, int y) {
        tate[y].erase(x);
        yoko[x].erase(y);
        rem--;
    };

    while(Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if(*tate[C].lower_bound(R) == R) {
            erase(R, C);
        }
        else {
            auto itr1 = tate[C].lower_bound(R);
            int x1 = *itr1, x2 = *--itr1;
            if(x1 != INF) {
                erase(x1, C);
            }
            if(x2 != -1) {
                erase(x2, C);
            }
            auto itr2 = yoko[R].lower_bound(C);
            int y1 = *itr2, y2 = *--itr2;
            if(y1 != INF) {
                erase(R, y1);
            }
            if(y2 != -1) {
                erase(R, y2);
            }
        }
    }

    cout << rem << endl;
}