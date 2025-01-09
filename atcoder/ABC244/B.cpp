#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Go Straight and Turn Right
//    https://atcoder.jp/contests/abc244/tasks/abc244_b



int main() {
    int N;
    string T;
    cin >> N >> T;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    int x = 0, y = 0, now = 0;

    for(int i = 0; i < N; i++) {
        if(T[i] == 'S') {
            x += dx[now];
            y += dy[now];
        }
        else {
            now = (now + 1) % 4;
        }
    }

    cout << x << " " << y << endl;
}