#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Adjacent Swaps 
//    https://atcoder.jp/contests/abc250/tasks/abc250_c



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> ball(N), pos(N);
    iota(ball.begin(), ball.end(), 0);
    iota(pos.begin(), pos.end(), 0);

    while(Q--) {
        int x;
        cin >> x;
        x--;
        if(ball[x] == N - 1) {
            int y = pos[N - 2];
            swap(pos[N - 1], pos[N - 2]);
            swap(ball[x], ball[y]);
        }
        else {
            int y = pos[ball[x] + 1];
            swap(pos[ball[x]], pos[ball[x] + 1]);
            swap(ball[x], ball[y]);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << pos[i] + 1 << " ";
        if(i == N - 1) cout << endl;
    }
}