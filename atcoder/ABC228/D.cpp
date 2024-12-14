#include <bits/stdc++.h>
using namespace std;


//    D - Linear Probing
//    https://atcoder.jp/contests/abc228/tasks/abc228_d



int main() {
    int N = 1 << 20;
    vector<long long> A(N, -1);
    set<int> S;
    for(int i = 0; i < N; i++) {
        S.insert(i);
    }

    int Q;
    cin >> Q;
    while(Q--) {
        int t;
        long long x;
        cin >> t >> x;

        int h = x % N;
        if(t == 1) {
            if(A[h] != -1) {
                auto itr = S.lower_bound(h);
                if(itr == S.end()) itr = *S.begin();
                A[*itr] = x;
                S.erase(itr);
            }
            else {
                A[h] = x;
                S.erase(h);
            }
        }
        if(t == 2) {
            cout << A[h] << endl;
        }
    }
}