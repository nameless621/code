#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Slot Strategy
//    https://atcoder.jp/contests/abc250/tasks/abc252_c



int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = INT_MAX;
    for(char c = '0'; c <= '9'; c++) {
        set<int> time;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 10; j++) {
                if(S[i][j] != c) continue;
                int t = j;
                while(time.count(t)) t += 10;
                time.insert(t);
            }
        }
        ans = min(ans, *prev(time.end()));
    }

    cout << ans << endl;
}