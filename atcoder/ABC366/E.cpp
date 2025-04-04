#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    E - Manhattan Multifocal Ellipse
//    https://atcoder.jp/contests/abc366/tasks/abc366_e



vector<long long> f(vector<int> vec) {
    int N = vec.size();
    int M = 1e6;
    long long sum = 0;
    for(int i = 0; i < N; i++) {
        vec[i] += M * 2;
        sum += vec[i];
    }
    vector<long long> res(M * 4 + 1);
    res[0] = sum;
    int j = 0;
    sort(vec.begin(), vec.end());
    for(int i = 1; i <= M * 4; i++) {
        while(j < N && vec[j] < i) j++;
        sum -= N - j * 2;
        res[i] = sum;
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    auto A = f(x);
    auto B = f(y);
    int j = B.size() - 1;
    long long ans = 0;
    for(int i = 0; i < (int)A.size(); i++) {
        while(j >= 0 && A[i] + B[j] > D) j--;
        ans += j + 1;
    }
    cout << ans << endl;
}