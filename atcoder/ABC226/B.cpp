#include <bits/stdc++.h>
using namespace std;


//        B - Counting Arrays
//        https://atcoder.jp/contests/abc226/tasks/abc226_b



int main() {
    int N;
    cin >> N;
    set<vector<int>> S;
    for(int i = 0; i < N; i++) {
        int L;
        cin >> L;
        vector<int> A(L);
        for(int j = 0; j < L; j++) {
            cin >> A[j];
        }
        S.insert(A);
    }
    cout << S.size() << endl;
}