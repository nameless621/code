#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    B - Grid Walk
//    https://atcoder.jp/contests/abc364/tasks/abc364_b



int main() {
    int H, W, Si, Sj;
    cin >> H >> W >> Si >> Sj;
    Si--; Sj--;

    vector<string> C(H);
    for(auto& c : C) cin >> c;

    string X;
    cin >> X;

    for(int k = 0; k < (int)X.size(); k++) {
        int i = Si, j = Sj;
        if(X[k] == 'L') j--;
        if(X[k] == 'R') j++;
        if(X[k] == 'U') i--;
        if(X[k] == 'D') i++;
        if(i < 0 || i >= H || j < 0 || j >= W || C[i][j] == '#') continue;
        Si = i;
        Sj = j;
    }

    cout << Si + 1 << " " << Sj + 1 << endl;
}