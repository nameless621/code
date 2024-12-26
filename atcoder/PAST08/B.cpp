#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - 積集合
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_b



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    vector<int> res;
    for(int i = 0; i < N; i++) {
        if(find(B.begin(), B.end(), A[i]) != B.end()) {
            res.push_back(A[i]);
        }
    }

    sort(res.begin(), res.end());
    for(int num : res) cout << num << " ";
    cout << endl;
}