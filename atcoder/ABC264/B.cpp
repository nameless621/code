#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;


//    B - Nice Grid
//    https://atcoder.jp/contests/abc264/tasks/abc264_b



vector<string> S = {"###############",
                    "#.............#",
                    "#.###########.#",
                    "#.#.........#.#",
                    "#.#.#######.#.#",
                    "#.#.#.....#.#.#",
                    "#.#.#.###.#.#.#",
                    "#.#.#.#.#.#.#.#",
                    "#.#.#.###.#.#.#",
                    "#.#.#.....#.#.#",
                    "#.#.#######.#.#",
                    "#.#.........#.#",
                    "#.###########.#",
                    "#.............#",
                    "###############",};

int main() {
    int R, C;
    cin >> R >> C;
    R--; C--;
    cout << (S[R][C] == '#' ? "black" : "white") << endl;
}