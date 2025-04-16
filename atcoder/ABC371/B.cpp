#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Taro
//    https://atcoder.jp/contests/abc371/tasks/abc371_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> ok(N+1);
    for(int i = 0; i < M; i++) {
        int A;
        char B;
        cin >> A >> B;
        if(!ok[A] && B == 'M') {
            cout << "Yes" << endl;
            ok[A] = true;
        }
        else {
            cout << "No" << endl;
        }
    }
}