#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Piano
//    https://atcoder.jp/contests/abc346/tasks/abc346_b



int main() {
    int W, B;
    cin >> W >> B;

    string T = "wbwbwwbwbwbw";
    string S;
    for(int i = 0; i < 1000; i++) S += T;

    bool ok = false;
    int N = S.size();
    for(int i = 0; i < N-W-B; i++) {
        int cntW = 0, cntB = 0;
        for(int j = i; j < i+W+B; j++) {
            if(S[j] == 'w') cntW++;
            else cntB++;
        }
        if(cntW == W && cntB == B) {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}