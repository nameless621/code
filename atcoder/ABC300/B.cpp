#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Same Map in the RPG World
//    https://atcoder.jp/contests/abc300/tasks/abc300_b



int main() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H), B(H);
    for(int i = 0; i < H; i++) cin >> A[i];
    for(int i = 0; i < H; i++) cin >> B[i];

    set<vector<string>> S;
    queue<vector<string>> q;
    q.push(A);
    S.insert(A);
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        auto temp = x;
        for(int i = 0; i < H-1; i++) swap(x[i], x[i+1]);
        if(!S.count(x)) {
            S.insert(x);
            q.push(x);
        }
        swap(x, temp);
        for(int j = 0; j < W-1; j++) {
            for(int i = 0; i < H; i++) {
                swap(x[i][j], x[i][j+1]);
            }
        }
        if(!S.count(x)) {
            S.insert(x);
            q.push(x);
        }
    }

    cout << (S.count(B) ? "Yes" : "No") << endl;
}