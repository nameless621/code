#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Apple Baskets on Circle
//    https://atcoder.jp/contests/abc270/tasks/abc270_e



int main() {
    int N;
    long long K;
    cin >> N >> K;

    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    auto check = [&](long long x) {
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            sum += min(A[i], x);
        }
        return sum <= K;
    };
    
    long long ok = 0, ng = 1e18;
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    vector<int> idx;
    for(int i = 0; i < N; i++) {
        K -= min(A[i], ok);
        A[i] = max(0ll, A[i] - ok);
        if(A[i] > 0) idx.push_back(i);
    }

    while(K) {
        vector<int> temp;
        for(int i : idx) {
            K--;
            A[i]--;
            if(K == 0) break;
            if(A[i] > 0) temp.insert(i);
        }
        swap(idx, temp);
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
        if(i == N - 1) cout << endl;
    }
}