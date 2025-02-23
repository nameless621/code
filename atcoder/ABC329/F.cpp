#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Colored Ball
//    https://atcoder.jp/contests/abc329/tasks/abc329_f



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<set<int>> box(N);
    for(int i = 0; i < N; i++) {
        int C;
        cin >> C;
        box[i].insert(C);
    }

    auto f = [&](int a, int b) {
        for(int ball : box[a]) {
            box[b].insert(ball);
        }
        box[a].clear();
    };

    while(Q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(box[a].size() < box[b].size()) {
            f(a, b);
        }
        else {
            swap(box[a], box[b]);
            f(a, b);
        }
        cout << box[b].size() << '\n';
    }
}