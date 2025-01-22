#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Last Rook
//    https://atcoder.jp/contests/abc269/tasks/abc269_e



int main() {
    int N;
    cin >> N;

    int ok = 1, ng = N;
    while(ok < ng) {
        int mid = (ok + ng) / 2;
        cout << "? " << ok << " " << mid << " " << 1 << " " << N << endl;
        int T;
        cin >> T;
        if(T <= mid - ok) ng = mid;
        else ok = mid + 1;
    }

    int X = ok;

    ok = 1; ng = N;
    while(ok < ng) {
        int mid = (ok + ng) / 2;
        cout << "? " << 1 << " " << N << " " << ok << " " << mid << endl;
        int T;
        cin >> T;
        if(T <= mid - ok) ng = mid;
        else ok = mid + 1;
    }

    int Y = ok;

    cout << "! " << X << " " << Y << endl;
}