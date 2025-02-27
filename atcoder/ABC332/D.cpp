#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Swapping Puzzle
//    https://atcoder.jp/contests/abc332/tasks/abc332_d



vector<vector<int>> read(int H, int W) {
    vector<vector<int>> res(H, vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> res[i][j];
        }
    }
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;

    auto A = read(H, W);
    auto B = read(H, W);

    map<vector<vector<int>>, int> dist;
    queue<vector<vector<int>>> q;

    auto push = [&](vector<vector<int>>& p, int d) {
        if(dist.count(p)) return;
        dist[p] = d + 1;
        q.push(p);
    };

    dist[A] = 0;
    q.push(A);
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int d = dist[p];
        for(int i = 0; i < H-1; i++) {
            swap(p[i], p[i+1]);
            push(p, d);
            swap(p[i], p[i+1]);
        }
        for(int j = 0; j < W-1; j++) {
            auto temp = p;
            for(int i = 0; i < H; i++) {
                swap(p[i][j], p[i][j+1]);
            }
            push(p, d);
            swap(p, temp);
        }
    }

    cout << (dist.count(B) ? dist[B] : -1) << endl;
}