#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Farthest Point
//    https://atcoder.jp/contests/abc348/tasks/abc348_b



int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    for(int i = 0; i < N; i++) {
        int res = -1, dist = 0;
        for(int j = 0; j < N; j++) {
            int x = X[i] - X[j];
            int y = Y[i] - Y[j];
            int d = x*x + y*y;
            if(dist < d) {
                res = j;
                dist = d;
            }
        }
        cout << res + 1 << endl;
    }
}