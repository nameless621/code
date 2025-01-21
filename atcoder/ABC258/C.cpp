#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Rotation
//    https://atcoder.jp/contests/abc258/tasks/abc258_c



int main() {
    int N, Q;
    string S;
    cin >> N >> Q >> S;

    int now = 0;
    while(Q--) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            now = (now + x) % N;
        }
        else {
            x--;
            x = (x - now + N) % N;
            cout << S[x] << endl;
        }
    }
}
