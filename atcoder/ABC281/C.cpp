#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    C - Circular Playlist
//    https://atcoder.jp/contests/abc281/tasks/abc281_c



int main() {
    int N;
    long long T;
    cin >> N >> T;

    vector<int> A(N);
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    T %= sum;
    for(int i = 0; i < N; i++) {
        if(T > A[i]) {
            T -= A[i];
        }
        else {
            cout << i + 1 << " " << T << endl;
            return 0;
        }
    }
}