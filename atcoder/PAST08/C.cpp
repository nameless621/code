#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - 出現回数
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_c



int main() {
    int N, X;
    cin >> N >> X;

    int count = 0;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if(A == X) count++;
    }

    cout << count << endl;
}