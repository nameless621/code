#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    I - 直通エレベーター
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_i



using P = pair<long long, long long>;

int main() {
    long long N;
    int M;
    cin >> N >> M;

    map<long long, vector<P>> G;
    vector<long long> temp = {1, N};
    for(int i = 0; i < M; i++) {
        long long A, B, C;
        cin >> A >> B >> C;
        G[A].emplace_back(B, C);
        G[B].emplace_back(A, C);
        temp.push_back(A);
        temp.push_back(B);
    }

    sort(temp.begin(), temp.end());
    for(int i = 0; i < (int)temp.size() - 1; i++) {
        long long A = temp[i], B = temp[i + 1];
        G[A].emplace_back(B, abs(A - B));
        G[B].emplace_back(A, abs(A - B));
    }

    map<long long, long long> result;
    result[1] = 0;
    priority_queue<P, vector<P>, greater<P>> PQ;
    PQ.emplace(0, 1);
    while(!PQ.empty()) {
        auto[dist, now] = PQ.top();
        PQ.pop();
        if(result[now] != dist) continue;
        for(auto[nex, cost] : G[now]) {
            long long sum = dist + cost;
            if(result.count(nex) && result[nex] <= sum) continue;
            result[nex] = sum;
            PQ.emplace(sum, nex);
        }
    }

    cout << result[N] << endl;
}