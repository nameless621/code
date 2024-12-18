#include <bits/stdc++.h>
using namespace std;


//    C - Swiss-System Tournament
//    https://atcoder.jp/contests/abc222/tasks/abc222_c



bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
    if (left.first == right.first) {
        return left.second < right.second;
    } else {
        return right.first < left.first;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    N *= 2;
    vector<string> A(N);
    for(int i = 0 ; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) {
        P[i].second = i;
    }

    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i += 2) {
            auto&[cnt1, idx1] = P[i];
            auto&[cnt2, idx2] = P[i + 1];
            if(A[idx1][j] == 'G' && A[idx2][j] == 'C') cnt1++;
            if(A[idx1][j] == 'C' && A[idx2][j] == 'P') cnt1++;
            if(A[idx1][j] == 'P' && A[idx2][j] == 'G') cnt1++;
            if(A[idx2][j] == 'G' && A[idx1][j] == 'C') cnt2++;
            if(A[idx2][j] == 'C' && A[idx1][j] == 'P') cnt2++;
            if(A[idx2][j] == 'P' && A[idx1][j] == 'G') cnt2++;
        }
        sort(P.begin(), P.end(), desc_asc);
    }

    for(int i = 0; i < N; i++) {
        cout << P[i].second + 1 << endl;
    }
}