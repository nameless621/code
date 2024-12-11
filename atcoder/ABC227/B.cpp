#include <bits/stdc++.h>
using namespace std;


//    B - KEYENCE building
//    https://atcoder.jp/contests/abc227/tasks/abc227_b



int main() {
    int N;
    cin >> N;
    
    vector<int> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    set<int> Area;
    for(int a = 1; a <= 1000; a++) {
        for(int b = 1; b <= 1000; b++) {
            int res = 4 * a * b + 3 * a + 3 * b;
            Area.insert(res);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(!Area.count(S[i])) {
            ans++;
        }
    }

    cout << ans << endl;
}