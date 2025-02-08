#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Cans and Openers
//    https://atcoder.jp/contests/abc312/tasks/abc312_f



int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A, B, C;
    for(int i = 0; i < N; i++) {
        int T, X;
        cin >> T >> X;
        if(T == 0) A.push_back(X);
        if(T == 1) B.push_back(X);
        if(T == 2) C.push_back(X);
    }

    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    while((int)A.size() > M) A.pop_back();
    long long sum = accumulate(A.begin(), A.end(), 0ll);

    M -= (int)A.size();
    long long op = 0;
    long long ans = sum;
    while(B.size()) {
        if(op == 0) {
            if(!C.size()) break;
            if(M > 0) {
                M--;
                op += C.back();
                C.pop_back();
            }
            else {
                if(!A.size()) break;
                op += C.back();
                C.pop_back();
                sum -= A.back();
                A.pop_back();
            }
        }
        if(M > 0) {
            M--;
            op--;
            sum += B.back();
            B.pop_back();
        }
        else {
            if(!A.size()) break;
            op--;
            sum -= A.back();
            A.pop_back();
            sum += B.back();
            B.pop_back();
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}