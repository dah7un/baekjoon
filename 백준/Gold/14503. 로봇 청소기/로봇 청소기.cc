// [14503] 로봇 청소기
// https://www.acmicpc.net/problem/14503
#include <iostream>

int N, M, cnt = 0;
int space[50][50];  // 0: none, 1: wall, 2: cleaned
int mov_forw[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int mov_back[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };

using namespace std;

int check_surr(int x, int y);
void clean_up(int x, int y, int d);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int r, c, d;

    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> space[i][j];
        }
    }

    clean_up(r, c, d);
    cout << cnt;

    return 0;
}

int check_surr(int x, int y) {
    int res = 1;     // not yet cleaned space left: 0

    for (int i = 0; i < 4; ++i) 
        res *= space[x + mov_forw[i][0]][y + mov_forw[i][1]];

    return res;
}

void clean_up(int x, int y, int d) {
    if (space[x][y] == 0) {
        space[x][y] = 2;
        ++cnt;
    }

    if (check_surr(x, y)) {
        x += mov_back[d][0];
        y += mov_back[d][1];

        if (space[x][y] == 1) return;
        else clean_up(x, y, d);
    }
    else {
        do {
            d = (d + 3) % 4;    // rotate 90 degrees counterclockwise
        } while (space[x + mov_forw[d][0]][y + mov_forw[d][1]]);
        clean_up(x + mov_forw[d][0], y + mov_forw[d][1], d);
    }
}