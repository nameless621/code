#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Best Performances
//    https://atcoder.jp/contests/abc306/tasks/abc306_e



int main() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(N);
    multiset<int> B, C;
    while((int)B.size() < K) B.insert(0);
    while((int)C.size() < N - K) C.insert(0);
    long long res = 0;
    while(Q--) {
        int X, Y;
        cin >> X >> Y;
        X--;
        auto itr = B.lower_bound(A[X]);
        if(*itr == A[X]) {
            res -= A[X];
            B.erase(itr);
        }
        else {
            auto it = C.lower_bound(A[X]);
            C.erase(it);
        }

        A[X] = Y;
        if((int)B.size() < K) {
            res += Y;
            B.insert(Y);
        }
        else {
            C.insert(Y);
        }
        
        if(C.size()) {
            int tempB = *B.begin();
            int tempC = *prev(C.end());
            if(tempB < tempC) {
                res -= tempB;
                res += tempC;
                B.erase(B.begin());
                B.insert(tempC);
                C.erase(prev(C.end()));
                C.insert(tempB);
            }
        }
        
        cout << res << endl;
    }
}