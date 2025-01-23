#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Previous Permutation
//    https://atcoder.jp/contests/abc276/tasks/abc276_c



int main() {
    int N;
    cin >> N;
    
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    prev_permutation(P.begin(), P.end());
    for(int i = 0; i < N; i++) cout << P[i] << " ";
    cout << endl;
}