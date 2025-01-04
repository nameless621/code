#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Sorting Queries
//    https://atcoder.jp/contests/abc217/tasks/abc217_e



int main() {
    int Q;
    cin >> Q;

    queue<int> q;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(Q--) {
        int t; cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            q.push(x);
        }
        if(t == 2) {
            if(pq.empty()) {
                cout << q.front() << endl;
                q.pop();
            }
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        if(t == 3) {
            while(!q.empty()) {
                pq.push(q.front());
                q.pop();
            }
        }
    }
}