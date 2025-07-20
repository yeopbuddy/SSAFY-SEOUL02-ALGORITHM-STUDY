// 문제 제목 : 불켜기
// 문제 난이도 : 골드 2
// 문제 요약 : 이동할 수 있는 조건이 정해져 있을 때의 2차원 BFS

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool lightson[101][101];
bool visit[101][101];

int main(){
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<vector<pair<int, int>>>> switches(N + 1, vector<vector<pair<int, int>>>(N + 1));
    
    for(int m = 0; m < M; m++){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        switches[a][b].push_back({x, y});
    }
    
    // 방에 도달하려면 불이 켜져 있어야 한다.
    // 방에 도달하려면 인접 좌표여야만 한다.
    // 방 도착을 visit으로 관리하고, 현재까지 도달한 방들을 deque에 넣어 관리한다.
    // deque의 요소들을 돌며 주변(상하좌우) 좌표 중 도착하지 않은 것들 중 불이 켜져 있는 것을 방문한다.

    deque<pair<int, int>> dq;
    deque<pair<int, int>> all;
    
    dq.push_back({1,1});
    all.push_back({1,1});
    
    visit[1][1] = true;
    lightson[1][1] = true;    
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(true){
        
        while(!dq.empty()){
            int px = dq.front().first;
            int py = dq.front().second;
            dq.pop_front();
            for(pair<int, int> p : switches[px][py]){
                lightson[p.first][p.second] = true;
            }
        }
        
        bool ischanged = false;
        
        for(pair<int, int> p : all){
            int px = p.first;
            int py = p.second;
            for(int i = 0; i < 4; i++){
                int nx = px + dx[i];
                int ny = py + dy[i];
                if(1 <= nx && nx <= N && 1 <= ny && ny <= N && !visit[nx][ny] && lightson[nx][ny]){
                    visit[nx][ny] = true;
                    dq.push_back({nx, ny});
                    all.push_back({nx, ny});
                    ischanged = true;
                }
            }
        }
        
        if(!ischanged){
            break;
        }
    }
    
    int Ans = 0;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(lightson[i][j]) Ans++;
        }
    }
    
    cout << Ans;
}