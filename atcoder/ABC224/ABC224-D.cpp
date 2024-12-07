#include <bits/stdc++.h>
using namespace std;


//    D - 8 Puzzle on Graph
//    https://atcoder.jp/contests/abc224/tasks/abc224_d
//
//
//    この問題は状態を頂点とした最短経路問題として解くことができる


int main() {
    int M;
    cin >> M;
    vector<vector<int>> Graph(9);
    for(int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    vector<int> position(9, 1e9);
    for(int i = 0; i < 8; i++) {
        int p;
        cin >> p;
        position[p - 1] = i;
    }

    map<vector<int>, int> dist;
    queue<vector<int>> Q;
    
    auto push = [&](vector<int> &x, int d) {
        int u = -1;
        //空の頂点を見つける
        for(int i = 0; i < 9; i++) {
            if(x[i] == 1e9) u = i;
        }

        //空の頂点と連結である頂点に置かれたコマを移動させる
        for(int v : Graph[u]) {
            swap(x[u], x[v]);
            //コマを移動させた時の状態が存在しなければキューに突っ込む
            if(!dist.count(x)) {
                dist[x] = d + 1;
                Q.push(x);
            }
            swap(x[u], x[v]);
        }
    };

    dist[position] = 0;
    Q.push(position);
    //幅優先探索を行う
    while(!Q.empty()) {
        auto x = Q.front();
        Q.pop();
        push(x, dist[x]);
    }


    sort(position.begin(), position.end());
    //条件を満たした状態が存在するか判定
    if(dist.count(position)) cout << dist[position] << endl;
    else cout << -1 << endl;
}
