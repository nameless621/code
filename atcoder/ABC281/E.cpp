#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Least Elements
//    https://atcoder.jp/contests/abc281/tasks/abc281_e



int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    multiset<int> S, T;
    T.insert(2e9);
    for(int i = 0; i < M; i++) {
        T.insert(A[i]);
    }

    long long res = 0;
    while((int)S.size() < K) {
        res += *T.begin();
        S.insert(*T.begin());
        T.erase(T.begin());
    }

    cout << res << " ";
    for(int i = M; i < N; i++) {
        if(S.count(A[i - M])) {
            auto itr = S.lower_bound(A[i - M]);
            S.erase(itr);
            res -= A[i - M];
        }
        else {
            auto itr = T.lower_bound(A[i - M]);
            T.erase(itr);
        }

        if((int)S.size() < K) {
            int temp = *T.begin();
            if(A[i] < temp) {
                S.insert(A[i]);
                res += A[i];
            }
            else {
                S.insert(temp);
                res += temp;
                T.erase(T.begin());
                T.insert(A[i]);
            }
        }
        else {
            int temp = *prev(S.end());
            if(A[i] < temp) {
                T.insert(temp);
                res -= temp;
                S.erase(prev(S.end()));
                S.insert(A[i]);
                res += A[i];
            }
            else {
                T.insert(A[i]);
            }
        }

        cout << res << " ";
    }
    cout << endl;
}