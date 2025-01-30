#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Kth Takoyaki Set
//    https://atcoder.jp/contests/abc297/tasks/abc297_e



int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    
    for(int i = 0; i < N; i++) cin >> A[i];

    set<long long> s;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    pq.push(0);
    while(K--) {
        long long x = pq.top();
        pq.pop();
        for(int i = 0; i < N; i++) {
            if(s.count(x + A[i])) continue;
            s.insert(x + A[i]);
            pq.push(x + A[i]);
        }
    }

    cout << pq.top() << endl;
}