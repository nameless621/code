#include <bits/stdc++.h>
using namespace std;


//        D - Teleportation
//        https://atcoder.jp/contests/abc226/tasks/abc226_d



int main() {
    int N;
    cin >> N;
    
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    set<pair<int, int>> S;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            int A = X[i] - X[j];
            int B = Y[i] - Y[j];
            int G = gcd(abs(A), abs(B));
            S.emplace(A / G, B / G);
        }
    }

    cout << S.size() << endl;
}