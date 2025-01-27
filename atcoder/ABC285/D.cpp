#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    D - Change Usernames
//    https://atcoder.jp/contests/abc285/tasks/abc285_d



int main() {
    int N;
    cin >> N;

    map<string, string> G;
    for(int i = 0; i < N; i++) {
        string S, T;
        cin >> S >> T;
        G[S] = T;
    }

    while(!G.empty()) {
        auto[S, T] = *G.begin();
        G.erase(G.begin());
        while(1) {
            string temp = T;
            if(G.count(T)) {
                T = G[T];
                G.erase(temp);
            }
            else break;

            if(S == T) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}