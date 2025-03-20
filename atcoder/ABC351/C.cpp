#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Merge the balls
//    https://atcoder.jp/contests/abc351/tasks/abc351_c



int main() {
    int N;
    cin >> N;

    vector<long long> res;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        res.push_back(A);
        int M = res.size();
        if(M <= 1) continue;
        if(res[M-1] != res[M-2]) continue;
        while(M >= 2 && res[M-1] == res[M-2]) {
            long long temp = res[M-1] + 1;
            res.pop_back();
            res.pop_back();
            res.push_back(temp);
            M--;
        }
    } 

    cout << res.size() << endl;
}