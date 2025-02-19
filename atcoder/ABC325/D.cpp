#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Printing Machine
//    https://atcoder.jp/contests/abc325/tasks/abc325_d



using P = pair<long long, long long>;

int main() {
    int N;
    cin >> N;

    priority_queue<P, vector<P>, greater<P>> p;
    for(int i = 0; i < N; i++) {
        long long T, D;
        cin >> T >> D;
        p.emplace(T, D);
    }

    int ans = 0;
    long long now = 1;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    while(!p.empty() || !q.empty()) {
        while(!p.empty() && p.top().first < now) p.pop();
        while(!p.empty() && p.top().first == now) {
            auto[T, D] = p.top();
            p.pop();
            q.push(T + D);
        }
        while(!q.empty() && q.top() < now) q.pop();
        if(!q.empty()) {
            ans++;
            q.pop();
        }
        while(!q.empty() && q.top() == now) q.pop();
        if(!q.empty()) now++;
        else if(!p.empty()) now = p.top().first;
    }

    cout << ans << endl;
}