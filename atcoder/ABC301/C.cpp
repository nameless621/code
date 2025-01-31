#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - AtCoder Cards
//    https://atcoder.jp/contests/abc301/tasks/abc301_c



int main() {
    string S, T;
    cin >> S >> T;

    vector<int> A(26), B(26);
    int cnt1 = 0, cnt2 = 0, N = S.size();
    for(int i = 0; i < N; i++) {
        if(S[i] == '@') cnt1++;
        else A[S[i] - 'a']++;
    }
    for(int i = 0; i < N; i++) {
        if(T[i] == '@') cnt2++;
        else B[T[i] - 'a']++;
    }

    string p = "atcoder";
    for(int i = 0; i < 26; i++) {
        if(A[i] < B[i]) {
            if(p.find(char('a' + i)) == string::npos || B[i] - A[i] > cnt1) {
                cout << "No" << endl;
                return 0;
            }
            cnt1 -= B[i] - A[i];
        }
        if(A[i] > B[i]) {
            if(p.find(char('a' + i)) == string::npos || A[i] - B[i] > cnt2) {
                cout << "No" << endl;
                return 0;
            }
            cnt2 -= A[i] - B[i];
        }
    }

    cout << "Yes" << endl;
}