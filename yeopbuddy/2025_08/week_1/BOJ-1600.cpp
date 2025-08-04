// 문제 제목 : 말이 되고픈 원숭이
// 문제 난이도 : 골드 3
// 문제 요약 : 체스의 나이트 이동 가능 횟수가 주어졌을 때, (0,0)에서 (H-1, W-1)까지 도달하는 최단 경로 구하기
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int visit[201][201][31];

int main() {

    int Ans = -1;
    int K, W, H;
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k <= K; k++) {
                visit[i][j][k] = 1e9;
            }
        }
    }

    vector<vector<int>> Chess(H, vector<int>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> Chess[i][j];
        }
    }

    deque<tuple<int, int, int, int>> dq;
    dq.push_back({ 0, 0, 0, 0 });

    visit[0][0][0] = 0;

    int dx1[4] = { 0,0,1,-1 };
    int dy1[4] = { 1,-1,0,0 };

    int dx2[8] = { -2,-2,-1,-1,1,1,2,2 };
    int dy2[8] = { -1,1,-2,2,-2,2,-1,1 };

    while (!dq.empty()) {

        int px, py, pt, pj;
        tie(px, py, pt, pj) = dq.front();
        dq.pop_front();

        if (px == H - 1 && py == W - 1) {
            if (Ans == -1) {
                Ans = pt;
            }
            else {
                Ans = min(Ans, pt);
            }
        }

        if (pj < K) {
            for (int i = 0; i < 8; i++) {
                int nx = px + dx2[i];
                int ny = py + dy2[i];
                if (0 <= nx && nx < H && 0 <= ny && ny < W && Chess[nx][ny] == 0 && visit[nx][ny][pj + 1] > pt + 1) {
                    visit[nx][ny][pj + 1] = pt + 1;
                    dq.push_back({ nx, ny, pt + 1, pj + 1 });
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = px + dx1[i];
            int ny = py + dy1[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && visit[nx][ny][pj] > pt + 1 && Chess[nx][ny] == 0) {
                visit[nx][ny][pj] = pt + 1;
                dq.push_back({ nx, ny, pt + 1, pj });
            }
        }
    }

    cout << Ans;

    return 0;
}