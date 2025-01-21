#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Number Box
//    https://atcoder.jp/contests/abc258/tasks/abc258_b



const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

int main() {
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    string ans = "";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 8; k++) {
                string temp;
                int x = i, y = j;
                for(int l = 0; l < N; l++) {
                    temp += A[x][y];
                    x = (x + dx[k] + N) % N;
                    y = (y + dy[k] + N) % N;
                }
                if(ans < temp) ans = temp;
            }
        }
    }

    cout << ans << endl;
}
