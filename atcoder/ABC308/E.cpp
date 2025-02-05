#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - MEX 
//    https://atcoder.jp/contests/abc308/tasks/abc308_e



int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    string S;
    cin >> S;

    vector<vector<int>> M(3);
    vector<vector<int>> E(3);
    vector<vector<int>> X(3);
    for(int i = 0; i < N; i++) {
        if(S[i] == 'M') M[A[i]].push_back(i);
        if(S[i] == 'E') E[A[i]].push_back(i);
        if(S[i] == 'X') X[A[i]].push_back(i);
    }

    long long ans = 0;
    set<int> s;
    for(int i = 0; i <= 3; i++) s.insert(i);

    for(int b = 0; b < 3; b++) {
        for(int j : E[b]) {
            vector<long long> cntM(3);
            vector<long long> cntX(3);
            for(int i = 0; i < 3; i++) {
                int res1 = lower_bound(M[i].begin(), M[i].end(), j) - M[i].begin();
                int res2 = lower_bound(X[i].begin(), X[i].end(), j) - X[i].begin();
                cntM[i] += res1;
                cntX[i] += (int)X[i].size() - res2;
            }

            auto temp = s;
            for(int a = 0; a <= 2; a++) {
                for(int c = 0; c <= 2; c++) {
                    s.erase(a);
                    s.erase(b);
                    s.erase(c);
                    long long t = *s.begin();
                    ans += t * cntM[a] * cntX[c];
                    s = temp;
                }
            }
        }
    }

    cout << ans << endl;
}