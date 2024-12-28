#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Who is missing?
//    https://atcoder.jp/contests/abc236/tasks/abc236_b



int main() {
    int N;
    cin >> N;
    
    vector<int> count(N);
    for(int i = 0; i < 4 * N - 1; i++) {
        int A;
        cin >> A;
        A--;
        count[A]++;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(count[i] == 3) {
            ans = i + 1;
        }
    }

    cout << ans << endl;
}