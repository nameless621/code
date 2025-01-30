#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Merge Sequences
//    https://atcoder.jp/contests/abc294/tasks/abc294_c



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    int len = N + M;
    vector<int> resA, resB;
    while(len > 0) {
        int X = 0, Y = 0;
        if(A.size()) X = A.back();
        if(B.size()) Y = B.back();
        if(X > Y) {
            resA.push_back(len);
            A.pop_back();
        }
        else {
            resB.push_back(len);
            B.pop_back();
        }
        len--;
    }

    reverse(resA.begin(), resA.end());
    reverse(resB.begin(), resB.end());
    
    for(int i = 0; i < N; i++) cout << resA[i] << " ";
    cout << endl;
    for(int i = 0; i < M; i++) cout << resB[i] << " ";
    cout << endl;
}