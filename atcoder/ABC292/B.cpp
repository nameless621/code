#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Yellow and Red Card
//    https://atcoder.jp/contests/abc292/tasks/abc292_b



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cnt(N);
    vector<bool> ban(N);
    while(Q--) {
        int T, x;
        cin >> T >> x;
        x--;
        if(T == 1) {
            cnt[x]++;
            if(cnt[x] > 1) ban[x] = true;
        }
        if(T == 2) {
            ban[x] = true;
        }
        if(T == 3) {
            cout << (ban[x] ? "Yes" : "No") << endl;
        }
    }
}