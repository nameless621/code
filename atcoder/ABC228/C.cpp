#include <bits/stdc++.h>
using namespace std;


//    C - Final Day
//    https://atcoder.jp/contests/abc228/tasks/abc228_c



int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        A[i].second = i;
        for(int j = 0; j < 3; j++) {
            int P;
            cin >> P;
            A[i].first += P;
        }
    }

    sort(A.rbegin(), A.rend());
    int border = A[K - 1].first;
    
    vector<bool> result(N);
    for(int i = 0; i < N; i++) {
        auto[sum, idx] = A[i];
        if(sum + 300 >= border) {
            result[idx] = true;
        }
    }

    for(int i = 0; i < N; i++) {
        if(result[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}