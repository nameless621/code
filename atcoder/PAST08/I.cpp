#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    I - /2 and *3
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_i



int main() {
    int N;
    cin >> N;

    int cnt = 0;
    priority_queue<long long, vector<long long>, greater<long long>> PQ;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        while(A % 2 == 0) {
            A /= 2;
            cnt++;
        }
        PQ.push(A);
    }

    while(cnt--) {
        long long X = PQ.top();
        PQ.pop();
        PQ.push(X * 3);
    }

    cout << PQ.top() << endl;
}
