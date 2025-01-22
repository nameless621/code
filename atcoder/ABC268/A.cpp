#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    A - Five Integers
//    https://atcoder.jp/contests/abc268/tasks/abc268_a



int main() {
    set<int> S;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        S.insert(x);
    }
    cout << S.size() << endl;
}