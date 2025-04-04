#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    D - Cuboid Sum Query
//    https://atcoder.jp/contests/abc366/tasks/abc366_d



class cumsum3D {
    private:
        vector<vector<vector<long long>>> S;
    
    public:
        cumsum3D(vector<vector<vector<int>>>& A, int n, int m, int l) {
            S = vector<vector<vector<long long>>>(n+1, vector<vector<long long>>(m+1, vector<long long>(l+1)));
            for (int x = 1; x <= n; x++) {
                for (int y = 1; y <= m; y++) {
                    for (int z = 1; z <= l; z++) {
                        S[x][y][z] = A[x-1][y-1][z-1] + S[x-1][y][z]
                                    + S[x][y-1][z] + S[x][y][z-1]
                                    - S[x-1][y-1][z] - S[x-1][y][z-1]
                                    - S[x][y-1][z-1] + S[x-1][y-1][z-1];
                    }
                }
            }
        }
    
        long long query(int Lx, int Rx, int Ly, int Ry, int Lz, int Rz) {
            Lx--; Ly--; Lz--;
            return S[Rx][Ry][Rz] - S[Lx][Ry][Rz] - S[Rx][Ly][Rz] - S[Rx][Ry][Lz]
                 + S[Lx][Ly][Rz] + S[Lx][Ry][Lz] + S[Rx][Ly][Lz] - S[Lx][Ly][Lz];
        }
};

int main() {
    int N;
    cin >> N;

    vector A(N, vector(N, vector<int>(N)));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                cin >> A[i][j][k];
            }
        }
    }

    cumsum3D S(A, N, N, N);

    int Q;
    cin >> Q;
    while(Q--) {
        int Lx, Rx, Ly, Ry, Lz, Rz;
        cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
        long long ret = S.query(Lx, Rx, Ly, Ry, Lz, Rz);
        cout << ret << endl;
    }
}