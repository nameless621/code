#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    E - Grid Filling
//    https://atcoder.jp/contests/abc278/tasks/abc278_e



int main() {
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    
    vector<vector<int>> A(H, vector<int>(W));
    map<int, int> cnt;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
            cnt[A[i][j]]++;
        }
    }

    auto check1 = [&](int x, int y) {
        for(int i = x; i < x + h; i++) {
            for(int j = y; j < y + w; j++) {
                cnt[A[i][j]]--;
                if(cnt[A[i][j]] == 0) cnt.erase(A[i][j]);
            }
        }
    };

    auto check2 = [&](int x, int y) {
        for(int i = x; i < x + h; i++) {
            cnt[A[i][y+w-1]]--;
            cnt[A[i][y-1]]++;
            if(cnt[A[i][y+w-1]] == 0) cnt.erase(A[i][y+w-1]);
        }

    };

    for(int i = 0; i <= H - h; i++) {
        map<int, int> temp = cnt;
        for(int j = 0; j <= W - w; j++) {
            if(j == 0) check1(i, j);
            else check2(i, j);
            cout << cnt.size() << " ";
        }
        cout << endl;
        swap(cnt, temp);
    }
}