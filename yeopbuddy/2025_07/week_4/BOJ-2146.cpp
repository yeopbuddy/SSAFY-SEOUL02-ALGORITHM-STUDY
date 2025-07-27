// 문제 제목 : 다리 만들기
// 문제 난이도 : 골드 3
// 문제 요약 : 주어진 영역들을 두개 이상의 영역을 이을 수 있는 가장 짧은 다리의 길이 출력

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> Island;

bool Visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool BeachCheck(int x, int y){ // 해변가(영역의 경계) 체크
    // int S = Island.size();
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < N && Island[nx][ny] == 0){
            return true;
        }
    }
    return false;
}

int main(){
    
    
    cin >> N;
    
    Island.resize(N, vector<int>(N));
    
    vector<vector<int>> Shortest(N, vector<int>(N, 1e9));
    vector<vector<int>> IslandIdx(N, vector<int>(N));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Island[i][j];
        }
    }
    
    int Idx = 1;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Island[i][j] == 1 && IslandIdx[i][j] == 0){
                IslandIdx[i][j] = Idx;
                deque<pair<int, int>> dq;
                dq.push_back({i, j});
                Visit[i][j] = true;
                while(!dq.empty()){
                    int px = dq.front().first;
                    int py = dq.front().second;
                    dq.pop_front();
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 <= nx && nx < N && 0 <= ny && ny < N && !Visit[nx][ny] && Island[nx][ny] == 1){
                            Visit[nx][ny] = true;
                            dq.push_back({nx, ny});
                            IslandIdx[nx][ny] = Idx;
                        }
                    }
                }
                Idx++;
            }
        }
    }
    
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << IslandIdx[i][j];
    //     }
    //     cout << "\n";
    // }
    
    int ans = 1e9;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(Island[i][j] == 1 && BeachCheck(i, j)){
                // 현재 인덱스가 아닌 최단 경로 찾기!
                memset(Visit, false, sizeof(Visit));
                Visit[i][j] = true;
                deque<tuple<int, int, int>> dq;
                dq.push_back({i, j, 0});
                // cout << "Find Beach! " << i << " " << j << "\n";
                while(!dq.empty()){
                    int px, py, pd;
                    tie(px, py, pd) = dq.front();
                    dq.pop_front();
                    
                    if(IslandIdx[px][py] != 0 && IslandIdx[px][py] != IslandIdx[i][j]){
                        ans = min(ans, pd);
                        break;
                    }
                    
                    for(int k = 0; k < 4; k++){
                        int nx = px + dx[k];
                        int ny = py + dy[k];
                        if(0 <= nx && nx < N && 0 <= ny && ny < N && !Visit[nx][ny] && IslandIdx[nx][ny] != IslandIdx[i][j]){
                            // cout << nx << " " << ny << " " << pd + 1 << "\n";
                            dq.push_back({nx, ny, pd + 1});
                            Visit[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ans - 1;
}