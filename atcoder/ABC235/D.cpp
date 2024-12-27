#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Multiply and Rotate
//    https://atcoder.jp/contests/abc235/tasks/abc235_d



int main() {
    int a, N;
    cin >> a >> N;

    unordered_map<int, int> dist;
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();
        if(!dist.count(x * a) && x * a <= 1e6) {
            dist[x * a] = dist[x] + 1;
            Q.push(x * a);
        }
        if(x >= 10 && x % 10 != 0) {
            string S = to_string(x);
            rotate(S.rbegin(), S.rbegin() + 1, S.rend());
            int temp = stoi(S);
            if(!dist.count(temp)) {
                dist[temp] = dist[x] + 1;
                Q.push(temp);
            }
        }
    }

    cout << (dist.count(N) ? dist[N] : -1) << endl;
}