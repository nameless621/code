#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    F - Bread
//    https://atcoder.jp/contests/abc252/tasks/abc252_f



int main() {
    int N;
    long long L;
    cin >> N >> L;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        pq.push(A);
        L -= A;
    }

    if(L > 0) pq.push(L);

    long long ans = 0;
    while((int)pq.size() > 1) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        ans += x + y;
        pq.push(x + y);
    }

    cout << ans << endl;
}
