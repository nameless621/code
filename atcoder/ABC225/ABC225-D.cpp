#include <bits/stdc++.h>
using namespace std;


//    D - Play Train 
//    https://atcoder.jp/contests/abc225/tasks/abc225_d



int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> front(N, -1), back(N, -1);
    while(Q--) {
        int T;
        cin >> T;
        if(T == 1) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            front[y] = x;
            back[x] = y;
        } 
        
        if(T == 2) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            front[y] = -1;
            back[x] = -1;
        }

        if(T == 3) {
            int x;
            cin >> x;
            x--;
            deque<int> res;
            res.push_back(x);

            //電車xの前側
            int now = x;
            while(1) {
                now = front[now];
                if(now == -1) break;
                res.push_front(now);
            }

            //電車xの後ろ側
            now = x;
            while(1) {
                now = back[now];
                if(now == -1) break;
                res.push_back(now);
            }

            cout << res.size() << " ";
            for(int num : res) cout << num + 1 << " ";
            cout << endl;
        }
    }
}