#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Don’t be cycle
//    https://atcoder.jp/contests/abc288/tasks/abc288_c



int main() {
    int N, M;
    cin >> N >> M;

    int cnt = 0;
    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        if(uf.same(A, B)) cnt++;
        else uf.merge(A, B);
    }

    cout << cnt << endl;
}