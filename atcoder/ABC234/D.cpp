#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Prefix K-th Max
//    https://atcoder.jp/contests/abc234/tasks/abc234_d



int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    set<int> S;
    for(int i = 0; i < K; i++) {
        S.insert(P[i]);
    }

    cout << *S.begin() << endl;
    
    for(int i = K; i < N; i++) {
        if(*S.begin() < P[i]) {
            S.erase(S.begin());
            S.insert(P[i]);
        }
        cout << *S.begin() << endl;
    }
}