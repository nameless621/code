#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - "redocta".swap(i,i+1)
//    https://atcoder.jp/contests/abc264/tasks/abc264_d



int main() {
    string S;
    cin >> S;

    map<string, int> dist;
    dist[S] = 0;
    queue<string> q;
    q.push(S);
    while(!q.empty()) {
        string x = q.front();
        q.pop();
        string temp = x;
        for(int i = 0; i < 6; i++) {
            swap(x[i], x[i+1]);
            if(!dist.count(x)) {
                dist[x] = dist[temp] + 1;
                q.push(x);
            }
            swap(x[i], x[i+1]);
        }
    }

    cout << dist["atcoder"] << endl;
}