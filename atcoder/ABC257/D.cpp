#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Jumping Takahashi 2
//    https://atcoder.jp/contests/abc257/tasks/abc257_d



int main() {
    int N;
    cin >> N;

    vector<long long> x(N), y(N), P(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> P[i];
    }

    auto check = [&](long long S) {
        for(int st = 0; st < N; st++) {
            vector<bool> visited(N);
            visited[st] = true;
            queue<int> q;
            q.push(st);
            while(!q.empty()) {
                int i = q.front();
                q.pop();
                for(int j = 0; j < N; j++) {
                    if(visited[j]) continue;
                    if(S * P[i] < abs(x[i] - x[j]) + abs(y[i] - y[j])) continue;
                    visited[j] = true;
                    q.push(j);
                }
            }
            bool ok = true;
            for(int i = 0; i < N; i++) {
                if(!visited[i]) ok = false;
            }
            if(ok) return true;
        }
        return false;
    };

    long long ng = 0, ok = 8e18 / *max_element(P.begin(), P.end());
    while(abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}
