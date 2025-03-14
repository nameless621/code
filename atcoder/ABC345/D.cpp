#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Tiling
//    https://atcoder.jp/contests/abc345/tasks/abc345_d



int main() {
    int N, H, W;
    cin >> N >> H >> W;

    vector<int> A(N), B(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        sum += A[i] * B[i];
    }

    if(sum < H * W) {
        cout << "No" << endl;
        return 0;
    }

    bool flag = false;
    vector<bool> used(N);
    vector<vector<bool>> ok(H, vector<bool>(W));
    auto f = [&](auto f, int rem) -> void {
        if(flag) return;
        if(rem == 0) {
            flag = true;
            return;
        }
        
        int i = -1, j = -1;
        for(int x = 0; x < H; x++) {
            if(i != -1) break;
            for(int y = 0; y < W; y++) {
                if(!ok[x][y]) {
                    i = x;
                    j = y;
                    break;
                }
            }
        }

        for(int k = 0; k < N; k++) {
            if(used[k] || flag) continue;
            if(rem - A[k] * B[k] < 0) continue;
            if(ok[i][j] || flag) continue;
            if(i + A[k] <= H && j + B[k] <= W) {
                bool check = true;
                for(int x = i; x < i + A[k]; x++) {
                    for(int y = j; y < j + B[k]; y++) {
                        if(ok[x][y]) check = false;
                    }
                }
                if(check) {
                    for(int x = i; x < i + A[k]; x++) {
                        for(int y = j; y < j + B[k]; y++) {
                            ok[x][y] = true;
                        }
                    }
                    used[k] = true;
                    f(f, rem - A[k] * B[k]);
                    used[k] = false;
                    for(int x = i; x < i + A[k]; x++) {
                        for(int y = j; y < j + B[k]; y++) {
                            ok[x][y] = false;
                        }
                    }
                }
            }
            if(i + B[k] <= H && j + A[k] <= W) {
                bool check = true;
                for(int x = i; x < i + B[k]; x++) {
                    for(int y = j; y < j + A[k]; y++) {
                        if(ok[x][y]) check = false;
                    }
                }
                if(check) {
                    for(int x = i; x < i + B[k]; x++) {
                        for(int y = j; y < j + A[k]; y++) {
                            ok[x][y] = true;
                        }
                    }
                    used[k] = true;
                    f(f, rem - A[k] * B[k]);
                    used[k] = false;
                    for(int x = i; x < i + B[k]; x++) {
                        for(int y = j; y < j + A[k]; y++) {
                            ok[x][y] = false;
                        }
                    }
                }
            }

        }
    };

    f(f, H * W);
    cout << (flag ? "Yes" : "No") << endl;
}