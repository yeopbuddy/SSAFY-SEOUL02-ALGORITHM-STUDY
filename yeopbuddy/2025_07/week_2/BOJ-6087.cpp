// 문제 제목 : 레이저 통신
// 문제 난이도 : 골드 3
// 문제 요약 : 두 지점을 연결하기 위해 필요한 최소한의 꺾임 횟수 찾기
#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
    
    int w, h;
    cin >> w >> h;
    
    vector<vector<char>> MAP(h, vector<char>(w));
    // vector<vector<int>> STEP(h, vector<int>(w, 1e9));
    vector<vector<vector<int>>> STEP(h, vector<vector<int>>(w, vector<int>(4, 1e9)));
    
    int cx1, cy1, cx2, cy2; bool fc = false;
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'C'){
                if(!fc){
                    cx1 = i; cy1 = j; fc = true;
                }else{
                    cx2 = i; cy2 = j;   
                }
            }
        }
    }
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    for(int i = 0; i < 4; i++){
        STEP[cx1][cy1][i] = 0;    
    }
    
    for(int i = 0; i < 4; i++){
        deque<tuple<int, int, int>> dq;
        dq.push_back({cx1, cy1, i});
        while(!dq.empty()){
            int px, py, pd;
            tie(px, py, pd) = dq.front();
            dq.pop_front();
            for(int j = 0; j < 4; j++){
                int nx = px + dx[j];
                int ny = py + dy[j];
                if(j == pd){
                    if(0 <= nx && nx < h && 0 <= ny && ny < w && MAP[nx][ny] != '*' && STEP[nx][ny][pd] > STEP[px][py][pd]){
                        STEP[nx][ny][pd] = STEP[px][py][pd];
                        dq.push_back({nx, ny, j});
                    }
                }else{
                    if(0 <= nx && nx < h && 0 <= ny && ny < w && MAP[nx][ny] != '*' && STEP[nx][ny][j] > STEP[px][py][pd] + 1){
                        STEP[nx][ny][j] = STEP[px][py][pd] + 1;
                        dq.push_back({nx, ny, j});
                    }
                }
            }
        }
    }
    
    cout << *min_element(STEP[cx2][cy2].begin(), STEP[cx2][cy2].end());
    
    return 0;
}