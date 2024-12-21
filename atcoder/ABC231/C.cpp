#include <bits/stdc++.h>
using namespace std;


//    C - Counting 2
//    https://atcoder.jp/contests/abc231/tasks/abc231_c



int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    while(Q--) {
        int x;
        cin >> x;
        int res = lower_bound(A.begin(), A.end(), x) - A.begin();
        cout << N - res << endl;
    }
}