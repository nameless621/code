#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Set Add Query
//    https://atcoder.jp/contests/abc347/tasks/abc347_e



int main() {
    int N, Q;
    cin >> N >> Q;

    long long sum = 0;
    vector<long long> A(N);
    set<int> S;
    while(Q--) {
        int x;
        cin >> x;
        x--;
        if(S.count(x)) {
            A[x] += sum;
            S.erase(x);
            sum += S.size();
        }
        else {
            A[x] -= sum;
            S.insert(x);
            sum += S.size();
        }
    }

    for(int x : S) {
        A[x] += sum;
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << (i < N-1 ? " " : "\n");
    }
}