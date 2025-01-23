#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Root M Leaper
//    https://atcoder.jp/contests/abc272/tasks/abc272_d



int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int>> s;
    for(int i = 0; i*i <= 1e6; i++) {
        for(int j = 0; j*j <= 1e6; j++) {
            int d = i*i + j*j;
            if(d == M) {
                s.insert({i, j});
                s.insert({-i, j});
                s.insert({i, -j});
                s.insert({-i, -j});
            }
            if(d > M) break;
        }
    }

    vector<vector<int>> dist(N, vector<int>(N, -1));
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for(auto[dx, dy] : s) {
            int i = x + dx;
            int j = y + dy;
            if(i < 0 || i >= N || j < 0 || j >= N) continue;
            if(dist[i][j] != -1) continue;
            dist[i][j] = dist[x][y] + 1;
            q.push({i, j});
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}