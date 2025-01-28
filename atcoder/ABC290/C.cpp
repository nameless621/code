#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Max MEX
//    https://atcoder.jp/contests/abc290/tasks/abc290_c



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    set<int> s;
    for(int i = 0; i <= N; i++) s.insert(i);
    
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    for(int i = 0; i < min((int)A.size(), K); i++) {
        s.erase(A[i]);
    }

    cout << *s.begin() << endl;
}