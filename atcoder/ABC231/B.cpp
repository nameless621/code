#include <bits/stdc++.h>
using namespace std;


//    B - Election
//    https://atcoder.jp/contests/abc231/tasks/abc231_b



int main() {
    int N;
    cin >> N;
    map<string, int> cnt;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        cnt[S]++;
    }

    int MAX = 0;
    string ans;
    for(auto[S, num] : cnt) {
        if(num > MAX) {
            MAX = num;
            ans = S;
        }
    }

    cout << ans << endl;
}