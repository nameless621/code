#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    K - 急ぎ旅
//    https://atcoder.jp/contests/past202107-open/tasks/past202107_k



using P = pair<long long, long long>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<P>> Graph(N);
    for(int i = 0; i < M; i++) {
        int U, V, T;
        cin >> U >> V >> T;
        U--; V--;
        Graph[U].emplace_back(V, T);
        Graph[V].emplace_back(U, T);
    }

    long long INF = LLONG_MAX;
    vector<P> result(N, {INF, 0});
    result[0] = P(0, A[0]);
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.emplace(0, 0);
    while(!Q.empty()) {
        auto[dist, now] = Q.top();
        Q.pop();
        if(result[now].first != dist) continue;
        for(auto[nex, cost] : Graph[now]) {
            long long sum = dist + cost;
            if(result[nex].first < sum) continue;
            if(result[nex].first == sum) {
                result[nex].second = max(result[nex].second, result[now].second + A[nex]);
            }
            else {
                result[nex].second = result[now].second + A[nex];
            }
            if(result[nex].first > sum) {
                result[nex].first = sum;
                Q.emplace(sum, nex);
            }
        }
    }

    cout << result[N-1].second << endl;
}