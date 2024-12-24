#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    L - たくさんの最小値
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_l



int op(int a, int b) { return min(a, b); }
int e() { return 1e9; }


int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    map<int, set<int>> MAP;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        MAP[A[i]].insert(i);
    }

    segtree<int, op, e> seg(A);

    while(Q--) {
        int T, X, Y;
        cin >> T >> X >> Y;
        if(T == 1) {
            X--;
            MAP[seg.get(X)].erase(X);
            MAP[Y].insert(X);
            seg.set(X, Y);
        }
        if(T == 2) {
            X--; Y--;
            int P = seg.prod(X, Y + 1);
            vector<int> res;
            while(1) {
                auto itr = MAP[P].lower_bound(X);
                if(itr == MAP[P].end() || *itr > Y) break;
                res.push_back(*itr);
                X = *itr + 1;
            }
            cout << res.size() << " ";
            for(int idx : res) cout << idx + 1 << " ";
            cout << endl;
        }
    }
}