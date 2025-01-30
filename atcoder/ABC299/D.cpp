#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Find by Query
//    https://atcoder.jp/contests/abc299/tasks/abc299_d



int main() {
    int N;
    cin >> N;

    int ok = 0, ng = N;
    while(abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        cout << "? " << mid << endl;
        int res;
        cin >> res;
        if(res == 0) ok = mid;
        else ng = mid;
    }

    cout << "! " << ok << endl;
}