#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    C - Ideal Sheet
//    https://atcoder.jp/contests/abc307/tasks/abc307_c



vector<string> read(int H) {
    vector<string> res(H);
    for(int i = 0; i < H; i++) cin >> res[i];
    return res;
}

vector<string> normalize(vector<string>& S, int H, int W) {
    vector<string> res(H, string(W, '.'));
    int x = 1e9, y = 1e9;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                x = min(x, i);
                y = min(y, j);
            }
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                res[i-x][j-y] = S[i][j];
            }
        }
    }
    return res;
}

bool check(vector<string>& S, int H, int W, int HX, int WX) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#' && (i >= HX || j >= WX)) {
                return true;
            }
        }
    }
    for(int i = 0; i < H; i++) {
        while((int)S[i].size() < WX) S[i] += '.';
        while((int)S[i].size() > WX) S[i].pop_back();
    }
    while((int)S.size() < HX) S.push_back(string(WX, '.'));
    while((int)S.size() > HX) S.pop_back();
    return false;
} 

bool move_right(vector<string>& S, int H, int W) {
    for(int i = 0; i < H; i++) {
        if(S[i][W-1] == '#') return false;
        rotate(S[i].rbegin(), S[i].rbegin()+1, S[i].rend());
    }
    return true;
}

bool move_down(vector<string>& S, int H, int W) {
    for(int j = 0; j < W; j++) {
        if(S[H-1][j] == '#') return false;
    }
    for(int i = H-1; i >= 1; i--) {
        swap(S[i], S[i-1]);
    }
    return true;
}

vector<vector<string>> enumeration(vector<string> S, int H, int W) {
    vector<vector<string>> res;
    do {
        vector<string> T = S;
        do {
            res.push_back(T);
        } while(move_right(T, H, W));
    } while(move_down(S, H, W));
    
    return res;
}

int main() {
    int HA, WA, HB, WB, HX, WX;
    cin >> HA >> WA;
    auto A = read(HA);
    
    cin >> HB >> WB;
    auto B = read(HB);

    cin >> HX >> WX;
    auto X = read(HX);

    A = normalize(A, HA, WA);
    B = normalize(B, HB, WB);
    
    if(check(A, HA, WA, HX, WX) || check(B, HB, WB, HX, WX)) {
        cout << "No" << endl;
        return 0;
    }

    auto resA = enumeration(A, HX, WX);
    auto resB = enumeration(B, HX, WX);

    bool ok = false;
    for(auto p : resA) {
        for(auto q : resB) {
            bool flag = true;
            for(int i = 0; i < HX; i++) {
                for(int j = 0; j < WX; j++) {
                    if(X[i][j] == '#' && p[i][j] == '.' && q[i][j] == '.') flag = false;
                    if(X[i][j] == '.' && (p[i][j] == '#' || q[i][j] == '#')) flag = false;
                }
            }
            if(flag) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
}