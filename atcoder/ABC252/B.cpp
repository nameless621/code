#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Takahashi's Failure 
//    https://atcoder.jp/contests/abc252/tasks/abc252_b



int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int max_A = *max_element(A.begin(), A.end());

    bool flag = false;
    for(int i = 0; i < K; i++) {
        int B;
        cin >> B;
        for(int j = 0; j < N; j++) {
            if(A[j] == max_A && j + 1 == B) {
                flag = true;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}
