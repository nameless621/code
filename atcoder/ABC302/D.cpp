#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};


//    D - Impartial Gift
//    https://atcoder.jp/contests/abc302/tasks/abc302_d



int main() {
    int N, M;
    long long D;
    cin >> N >> M >> D;

    vector<long long> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(B.begin(), B.end());
    long long ans = -1;
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(B.begin(), B.end(), A[i] + D);
        if(itr == B.end()) *itr--;
        if(abs(A[i] - *itr) <= D) ans = max(ans, A[i] + *itr);
        if(itr != B.begin()) *itr--;
        if(abs(A[i] - *itr) <= D) ans = max(ans, A[i] + *itr);
    }

    cout << ans << endl;
}