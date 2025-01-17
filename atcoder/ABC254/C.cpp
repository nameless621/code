#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - K Swap
//    https://atcoder.jp/contests/abc254/tasks/abc254_c



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> B(N);
    for(int i = 0; i < K; i++) {
        vector<int> temp;
        for(int j = i; j < N; j += K) {
            temp.push_back(A[j]);
        }
        sort(temp.begin(), temp.end());
        int idx = 0;
        for(int j = i; j < N; j += K) {
            B[j] = temp[idx];
            idx++;
        }
    }

    sort(A.begin(), A.end());
    cout << (A == B ? "Yes" : "No") << endl;
}