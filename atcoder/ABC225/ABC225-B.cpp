#include <bits/stdc++.h>
using namespace std;


//    B - Star or Not
//    https://atcoder.jp/contests/abc225/tasks/abc225_b



int main() {
    int N;
    cin >> N;
    vector<int> cnt(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
    }

    bool ok = false;
    for(int i = 0; i < N; i++) {
        if(cnt[i] == N - 1) {
            ok = true;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}