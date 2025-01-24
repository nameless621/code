#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - All Assign Point Add
//    https://atcoder.jp/contests/abc278/tasks/abc278_d



int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int Q;
    cin >> Q;

    bool flag = false;
    long long base = -1;
    map<int, long long> sum;
    while(Q--) {
        int T;
        cin >> T;
        if(T == 1) {
            int x;
            cin >> x;
            flag = true;
            base = x;
            sum.clear();
        }
        if(T == 2) {
            int i, x;
            cin >> i >> x;
            i--;
            if(flag) sum[i] += x;
            else A[i] += x;
        }
        if(T == 3) {
            int i;
            cin >> i;
            i--;
            if(flag) {
                cout << base + sum[i] << endl;
            }
            else {
                cout << A[i] << endl;
            }
        }
    }
}