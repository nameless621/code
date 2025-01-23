#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - LRUD Instructions
//    https://atcoder.jp/contests/abc273/tasks/abc273_d



int main() {
    int H, W, x, y, N;
    cin >> H >> W >> x >> y >> N;

    map<int, vector<int>> tate, yoko;
    for(int i = 0; i < N; i++) {
        int r, c;
        cin >> r >> c;
        tate[c].push_back(r);
        yoko[r].push_back(c);
    } 

    for(auto&[k, v] : tate) {
        v.push_back(-1);
        v.push_back(2e9);
        sort(v.begin(), v.end());  
    } 
    for(auto&[k, v] : yoko) {
        v.push_back(-1);
        v.push_back(2e9);
        sort(v.begin(), v.end());  
    } 


    auto f1 = [&](vector<int>& vec, int p, int l) {
        int np = max(1, p - l);
        if(!vec.size()) return np;
        auto itr = lower_bound(vec.begin(), vec.end(), p);
        itr--;
        if(np <= *itr && *itr < p) return *itr + 1; 
        else return np;
    };

    auto f2 = [&](vector<int>& vec, int p, int l, int P) {
        int np = min(P, p + l);
        if(!vec.size()) return np;
        auto itr = lower_bound(vec.begin(), vec.end(), p);
        if(p < *itr && *itr <= np) return *itr - 1;
        else return np;
    };

    int Q;
    cin >> Q;
    while(Q--) {
        char d;
        int l;
        cin >> d >> l;
        if(d == 'L') {
            y = f1(yoko[x], y, l);
        }
        if(d == 'R') {
            y = f2(yoko[x], y, l, W);
        }
        if(d == 'U') {
            x = f1(tate[y], x, l);
        }
        if(d == 'D') {
            x = f2(tate[y], x, l, H);
        }

        cout << x << " " << y << endl;
    }
}