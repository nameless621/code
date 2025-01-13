#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Four Points
//    https://atcoder.jp/contests/abc246/tasks/abc246_a



int main() {
    map<int, int> a, b;
    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
    }

    int x = 0, y = 0;
    for(auto[k, v] : a) {
        if(v == 1) x = k;
    }
    for(auto[k, v] : b) {
        if(v == 1) y = k;
    }

    cout << x << " " << y << endl;
}