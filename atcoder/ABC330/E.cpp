#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Mex and Update
//    https://atcoder.jp/contests/abc330/tasks/abc330_e



int main() {
    int N, Q;
    cin >> N >> Q;

    
    set<int> MEX;
    for(int i = 0; i <= N; i++) {
        MEX.insert(i);
    }

    vector<int> A(N);
    map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
        MEX.erase(A[i]);
    }

    while(Q--) {
        int i, x;
        cin >> i >> x;
        i--;

        cnt[A[i]]--;
        if(cnt[A[i]] == 0) {
            MEX.insert(A[i]);
        }
        cnt[x]++;
        MEX.erase(x);
        A[i] = x;

        cout << *MEX.begin() << '\n';
    }
}