#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - False Hope
//    https://atcoder.jp/contests/abc319/tasks/abc319_c



int main() {
    int c[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> c[i][j];
        }
    }

    vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    double sum = 1, cnt = 0;
    for(int i = 1; i <= 9; i++) {
        sum *= i;
    }

    do {
        bool NG = false;
        vector<int> x1, x2, x3, y1, y2, y3, d1, d2;
        for(int i = 0; i < 9; i++) {
            int x = p[i]/3;
            int y = p[i]%3;
            if(x == 0) x1.push_back(c[x][y]);
            if(x == 1) x2.push_back(c[x][y]);
            if(x == 2) x3.push_back(c[x][y]);
            if(y == 0) y1.push_back(c[x][y]);
            if(y == 1) y2.push_back(c[x][y]);
            if(y == 2) y3.push_back(c[x][y]);
            if(x == y) {
                d1.push_back(c[x][y]);
                if(x == 1) d2.push_back(c[x][y]);
            }
            if((x == 2 && y == 0) || (x == 0 && y == 2)) d2.push_back(c[x][y]);
            if(x1.size() == 3 && x1[0] == x1[1] && x1[0] != x1[2]) NG = true;
            if(x2.size() == 3 && x2[0] == x2[1] && x2[0] != x2[2]) NG = true;
            if(x3.size() == 3 && x3[0] == x3[1] && x3[0] != x3[2]) NG = true;
            if(y1.size() == 3 && y1[0] == y1[1] && y1[0] != y1[2]) NG = true;
            if(y2.size() == 3 && y2[0] == y2[1] && y2[0] != y2[2]) NG = true;
            if(y3.size() == 3 && y3[0] == y3[1] && y3[0] != y3[2]) NG = true;
            if(d1.size() == 3 && d1[0] == d1[1] && d1[0] != d1[2]) NG = true;
            if(d2.size() == 3 && d2[0] == d2[1] && d2[0] != d2[2]) NG = true;
        }
        if(NG) cnt++;
    } while(next_permutation(p.begin(), p.end()));

    cout << fixed << setprecision(12) << (sum - cnt) / sum << endl;
}