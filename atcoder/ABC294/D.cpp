#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Bank
//    https://atcoder.jp/contests/abc294/tasks/abc294_d



int main() {
    int N, Q;
    cin >> N >> Q;

    int now = 1;
    set<int> s;
    while(Q--) {
        int T;
        cin >> T;
        if(T == 1) {
            s.insert(now);
            now++;
        }
        if(T == 2) {
            int x;
            cin >> x;
            s.erase(x);
        }
        if(T == 3) {
            cout << *s.begin() << endl;
        }
    }
}