#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - キーボード
//    https://atcoder.jp/contests/past202112-open/tasks/past202112_e



bool left(int x) { return (1 <= x && x <= 5); }
bool right(int x) { return (6 <= x || x == 0); }

int main() {
    string N;
    cin >> N;
    
    int ans = 500;
    for(int i = 1; i < (int)N.size(); i++) {
        if(N[i] == N[i - 1]) ans += 301;
        else if(left(N[i] - '0') && left(N[i - 1] - '0')) ans += 210;
        else if(right(N[i] - '0') && right(N[i - 1] - '0')) ans += 210;
        else ans += 100;
    }

    cout << ans << endl;
}