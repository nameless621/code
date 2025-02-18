#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - World Tour Finals
//    https://atcoder.jp/contests/abc323/tasks/abc323_c



int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i];

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    for(int i = 0; i < N; i++) {
        int sum = i+1;
        vector<int> B;
        for(int j = 0; j < M; j++) {
            if(S[i][j] == 'o') sum += A[j];
            else B.push_back(A[j]);
        }
        sort(B.begin(), B.end());

        int tot = 0;
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            int temp = j+1;
            for(int k = 0; k < M; k++) {
                if(S[j][k] == 'o') {
                    temp += A[k];
                }
            }
            tot = max(tot, temp);
        }

        int res = 0;
        while(sum <= tot) {
            sum += B.back();
            B.pop_back();
            res++;
        }

        cout << res << endl;
    }
}