#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;


//    A - Legendary Players
//    https://atcoder.jp/contests/abc319/tasks/abc319_a



int main() {
    vector<string> name = {"tourist", "ksun48", "Benq", "Um_nik", "apiad", "Stonefeang", "ecnerwala", "mnbvmar", "newbiedmy", "semiexp"};
    vector<int> rate = {3858, 3679, 3658, 3648, 3638, 3630, 3613, 3555, 3516, 3481};

    string S;
    cin >> S;

    int idx = find(name.begin(), name.end(), S) - name.begin();
    cout << rate[idx] << endl;
}