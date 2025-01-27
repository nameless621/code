#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - First Query Problem 
//    https://atcoder.jp/contests/abc283/tasks/abc283_b



int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int Q;
    cin >> Q;
    while(Q--) {
        int T;
        cin >> T;
        if(T == 1) {
            int k, x;
            cin >> k >> x;
            k--;
            A[k] = x;
        }
        if(T == 2) {
            int k;
            cin >> k;
            k--;
            cout << A[k] << endl;
        }
    }
}