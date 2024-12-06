#include <bits/stdc++.h>
using namespace std;


//https://atcoder.jp/contests/abc223/tasks/abc223_d


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> deg(N);
    vector<vector<int>> Graph(N);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        Graph[A].push_back(B);
        deg[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i = 0; i < N; i++) {
        if(deg[i] == 0) {
            PQ.push(i);
        }
    }

    vector<int> ans;
    while(!PQ.empty()) {
        int u = PQ.top();
        PQ.pop();
        ans.push_back(u);
        for(int v : Graph[u]) {
            deg[v]--;
            if(deg[v] == 0) {
                PQ.push(v);
            }
        }
    }

    if((int)ans.size() != N) {
        cout << -1 << endl;
    }
    else {
        for(int i = 0; i < N; i++) {
            cout << ans[i] + 1;
            if(i < N-1) cout << " ";
        }
        cout << endl;
    }
}