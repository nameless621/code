#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Sierpinski carpet
//    https://atcoder.jp/contests/abc357/tasks/abc357_c



int main() {
    int N;
    cin >> N;

    int N3 = pow(3, N);
    vector<string> S(N3, string(N3, '.'));
    auto f = [&](auto f, int x, int y, int K) -> void {
        if(K == 0) {
            S[x][y] = '#';
            return;
        }

        int m = pow(3, K-1);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i != 1 || j != 1) {
                    f(f, x+i*m, y+j*m, K-1);
                }
            }
        }
    };

    f(f, 0, 0, N);
    for(string s : S) {
        cout << s << endl;
    }
}