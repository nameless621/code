#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Count Distinct Integers
//    https://atcoder.jp/contests/abc240/tasks/abc240_b



int main() {
    int N;
    cin >> N;

    set<int> S;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        S.insert(a);
    }

    cout << S.size() << endl;
}