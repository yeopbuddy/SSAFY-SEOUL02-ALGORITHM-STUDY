// 문제 제목 : Baaaaaaaaaduk2 (Easy)
// 문제 난이도 : 골드 3
// 문제 요약 : 현재 바둑 판에서 돌을 2개 더 놓을 때, 먹을 수 있는 최대 돌의 개수 구하기
#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <tuple>
using namespace std;
int N, M;
int Ans = 0;

vector<vector<int>> Baduk;
vector<pair<int, int>> Empty;
bool visit[21][21];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Calculate(int x1, int y1, int x2, int y2) {
    int Kill = 0; // 현재 두 돌을 놓았을 때 잡을 수 있는 총 돌의 개수
    Baduk[x1][y1] = 1; Baduk[x2][y2] = 1; // 돌 놓기

    memset(visit, false, sizeof(visit)); // visit 배열 초기화

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visit[i][j] && Baduk[i][j] == 2) { // 방문하지 않은 상대 돌 (새 그룹의 시작)
                int Cnt = 0; // 현재 그룹의 돌 개수
                bool Open = false; // 현재 그룹의 활로 여부
                deque<pair<int, int>> dq;

                dq.push_back({ i, j });
                visit[i][j] = true;

                while (!dq.empty()) {
                    int px = dq.front().first;
                    int py = dq.front().second;
                    dq.pop_front();

                    Cnt++;

                    for (int k = 0; k < 4; k++) {
                        int nx = px + dx[k];
                        int ny = py + dy[k];

                        if (0 <= nx && nx < N && 0 <= ny && ny < M && !visit[nx][ny]) {
                            if (Baduk[nx][ny] == 2) {
                                visit[nx][ny] = true;
                                dq.push_back({ nx, ny });
                            }
                            else if (Baduk[nx][ny] == 0) { // 빈 공간 (활로) 발견
                                Open = true;
                            }
                        }
                    }
                }

                // 한 그룹의 탐색이 완료된 후
                if (!Open) {
                    Kill += Cnt;
                }
            }
        }
    }
    Baduk[x1][y1] = 0; Baduk[x2][y2] = 0;
    Ans = max(Kill, Ans);
}

int main() {

    cin >> N >> M;
    Baduk.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Baduk[i][j];
            if (Baduk[i][j] == 0) {
                Empty.push_back({ i, j });
            }
        }
    }

    for (int i = 0; i < Empty.size(); i++) {
        for (int j = i + 1; j < Empty.size(); j++) {
            Calculate(Empty[i].first, Empty[i].second, Empty[j].first, Empty[j].second);
        }
    }

    cout << Ans;

    return 0;
}