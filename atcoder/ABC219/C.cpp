#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Neo-lexicographic Ordering
//    https://atcoder.jp/contests/abc219/tasks/abc219_c



int main() {
    string X;
    int N;
    cin >> X >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<int> P(26);
    for(int i = 0; i < 26; i++) P[X[i] - 'a'] = i;

    sort(S.begin(), S.end(), [&](const string& A, const string& B) {
        int len = min(A.size(), B.size());
        for(int i = 0; i < len; i++) {
            if(A[i] != B[i]) return P[A[i] - 'a'] < P[B[i] - 'a'];
        }
        return A.size() < B.size();
    });

    for(int i = 0; i < N; i++) cout << S[i] << endl;
}