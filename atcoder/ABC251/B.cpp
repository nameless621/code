#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - At Most 3 (Judge ver.)
//    https://atcoder.jp/contests/abc250/tasks/abc251_b



int main() {
    int N, W;
    cin >> N >> W;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    set<int> s;
    for(int i = 0; i < N; i++) {
        if(A[i] <= W) s.insert(A[i]);
        for(int j = i + 1; j < N; j++) {
            if(A[i] + A[j] <= W) s.insert(A[i] + A[j]);
            for(int k = j + 1; k < N; k++) {
                if(A[i] + A[j] + A[k] <= W) s.insert(A[i] + A[j] + A[k]);
            }
        }
    }

    cout << s.size() << endl;
}