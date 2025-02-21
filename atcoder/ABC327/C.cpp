#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Number Place
//    https://atcoder.jp/contests/abc327/tasks/abc327_c



int main() {
    int A[9][9];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> A[i][j];
        }
    }

    bool ok = true;
    for(int i = 0; i < 9; i++) {
        set<int> s;
        for(int j = 0; j < 9; j++) {
            s.insert(A[i][j]);
        }
        if((int)s.size() != 9) ok = false;
    }

    for(int j = 0; j < 9; j++) {
        set<int> s;
        for(int i = 0; i < 9; i++) {
            s.insert(A[i][j]);
        }
        if((int)s.size() != 9) ok = false;
    }

    for(int i = 0; i < 9; i += 3) {
        for(int j = 0; j < 9; j += 3) {
            set<int> s;
            for(int x = i; x < i+3; x++) {
                for(int y = j; y < j+3; y++) {
                    s.insert(A[x][y]);
                }
            }
            if((int)s.size() != 9) ok = false;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}