#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Go Stone Puzzle
//    https://atcoder.jp/contests/abc361/tasks/abc361_d



int main() {
    int N;
    string S, T;
    cin >> N >> S >> T;

    N += 2;
    S += "..";
    T += "..";

    map<string, int> dist;
    dist[S] = 0;
    queue<string> q;
    q.push(S);
    while(!q.empty()) {
        string p = q.front();
        q.pop();
        int j = -1, d = dist[p];
        for(int i = 0; i < N; i++) {
            if(p[i] == '.') {
                j = i;
                break;
            }
        }

        for(int i = 0; i < N-1; i++) {
            if(p[i] == '.' || p[i+1] == '.') continue;
            swap(p[i], p[j]);
            swap(p[i+1], p[j+1]);
            if(!dist.count(p)) {
                dist[p] = d + 1;
                q.push(p);
            }
            swap(p[i], p[j]);
            swap(p[i+1], p[j+1]);
        }
    }

    if(dist.count(T)) cout << dist[T] << endl;
    else cout << -1 << endl;
}