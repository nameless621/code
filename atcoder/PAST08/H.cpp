#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    H - 最短経路
//    https://atcoder.jp/contests/past202109-open/tasks/past202109_h



int main() {
    int N, X;
    cin >> N >> X;

    vector<vector<pair<int, int>>> Graph(N);
    for(int i = 0; i < N - 1; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--;
        Graph[A].emplace_back(B, C);
        Graph[B].emplace_back(A, C);
    }

    int INF = INT_MAX;
    bool ok = false;
    for(int i = 0; i < N; i++) {
        vector<int> result(N, INF);
        result[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        PQ.emplace(0, i);
        while(!PQ.empty()) {
            auto[dist, u] = PQ.top();
            PQ.pop();
            if(result[u] != dist) continue;
            for(auto[v, cost] : Graph[u]) {
                int sum = dist + cost;
                if(result[v] <= sum) continue;
                result[v] = sum;
                PQ.emplace(sum, v);
            }
        }

        for(int j = 0; j < N; j++) {
            if(result[j] == X) {
                ok = true;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}