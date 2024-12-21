#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Neighbors
//    https://atcoder.jp/contests/abc231/tasks/abc231_d



int main() {
    int N, M;
    cin >> N >> M;

    bool ok = true;
    dsu uf(N);
    vector<int> cnt(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        if(uf.same(A, B)) ok = false;
        uf.merge(A, B);
        cnt[A]++;
        cnt[B]++;
        if(cnt[A] > 2 || cnt[B] > 2) ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}