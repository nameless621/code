#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    F - Add One Edge 3
//    https://atcoder.jp/contests/abc401/tasks/abc401_f



int N1, N2;
vector<vector<int>> read(int& N) {
    cin >> N;
    vector<vector<int>> res(N);
    for(int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        res[u].push_back(v);
        res[v].push_back(u);
    }
    return res;
}

void dfs(vector<vector<int>>& G, vector<int>& d, int u, int pre) {
    for(int v : G[u]) {
        if(v == pre) continue;
        d[v] = d[u] + 1;
        dfs(G, d, v, u);
    }
    return;
}

vector<int> f(vector<vector<int>> G, int N) {
    vector<int> dist(N);
    dfs(G, dist, 0, -1);

    int idx1 = max_element(dist.begin(), dist.end()) - dist.begin();
    vector<int> d1(N);
    dfs(G, d1, idx1, -1);

    int idx2 = max_element(d1.begin(), d1.end()) - d1.begin();
    vector<int> d2(N);
    dfs(G, d2, idx2, -1);

    vector<int> res(N);
    for(int i = 0; i < N; i++) {
        res[i] = max(d1[i], d2[i]);
    }

    return res;
}

int main() {
    vector<vector<int>> S = read(N1);
    vector<vector<int>> T = read(N2);

    vector<int> A = f(S, N1);
    vector<int> B = f(T, N2);

    int d1 = *max_element(A.begin(), A.end());
    int d2 = *max_element(B.begin(), B.end());
    long long M = max(d1, d2);

    sort(B.begin(), B.end());
    vector<long long> sum(N2+1);
    for(int i = 0; i < N2; i++) {
        sum[i+1] = sum[i] + B[i];
    }

    long long ans = 0;
    for(int i = 0; i < N1; i++) {
        int x = M - A[i] - 1;
        int j = lower_bound(B.begin(), B.end(), x) - B.begin();
        long long rem = N2 - j;
        ans += M * j;
        ans += rem * A[i] + (sum[N2] - sum[j]) + rem;
    }

    cout << ans << endl;
}