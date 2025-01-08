#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Hit and Blow
//    https://atcoder.jp/contests/abc243/tasks/abc243_b



int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    int ans1 = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) ans1++;
    }

    int ans2 = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(A[i] == B[j]) ans2++;
        }
    }

    cout << ans1 << endl;
    cout << ans2 << endl;
}