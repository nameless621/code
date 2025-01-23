#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Robot Arms 2
//    https://atcoder.jp/contests/abc274/tasks/abc274_d



int main() {
    int N, x, y;
    cin >> N >> x >> y;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    set<int> dpx, dpy;
    dpx.insert(A[0]);
    dpy.insert(0);
    for(int i = 1; i < N; i++) {
        if(i & 1) {
            set<int> py;
            swap(dpy, py);
            for(int p : py) {
                dpy.insert(p + A[i]);
                dpy.insert(p - A[i]);
            }
        }
        else {
            set<int> px;
            swap(dpx, px);
            for(int p : px) {
                dpx.insert(p + A[i]);
                dpx.insert(p - A[i]);
            }
        }
    }

    cout << (dpx.count(x) && dpy.count(y) ? "Yes" : "No") << endl;
}