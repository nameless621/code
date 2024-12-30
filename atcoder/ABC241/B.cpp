#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Pasta 
//    https://atcoder.jp/contests/abc241/tasks/abc241_b



int main() {
    int N, M;
    cin >> N >> M;
    
    map<int, int> cnt;
    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;
        cnt[A]++;
    }

    bool ok = true;
    for(int i = 0; i < M; i++) {
        int B;
        cin >> B;
        if(cnt[B] > 0) cnt[B]--;
        else ok = false;
    }

    cout << (ok ? "Yes" : "No") << endl;
}