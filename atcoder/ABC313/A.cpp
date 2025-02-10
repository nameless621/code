#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - To Be Saikyo
//    https://atcoder.jp/contests/abc313/tasks/abc313_a



int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int maxP = *max_element(P.begin(), P.end());
    int x = 10101;
    for(int i = 1; i < N; i++) {
        if(P[i] == maxP) {
            x = min(x, P[i] - P[0] + 1);
        }
    }

    if(x == 10101) x = 0;
    cout << x << endl;
}