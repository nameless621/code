#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Inverse of Permutation
//    https://atcoder.jp/contests/abc217/tasks/abc217_c



int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    vector<int> res(N);
    for(int i = 0; i < N; i++) {
        P[i]--;
        res[P[i]] = i + 1;
    }

    for(int i = 0; i < N; i++) cout << res[i] << " ";
    cout << endl;
}