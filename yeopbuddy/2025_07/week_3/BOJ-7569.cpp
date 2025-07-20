// 문제 제목 : 토마토
// 문제 난이도 : 골드 5
// 문제 요약 : 3차원 BFS

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;
int main(){
    
    int M, N, H;
    cin >> M >> N >> H;
    
    vector<vector<vector<int>>> Tomato(N, vector<vector<int>>(M, vector<int>(H)));
    
    deque<tuple<int, int, int, int>> dq;
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                cin >> Tomato[j][k][i];
                if(Tomato[j][k][i] == 1){
                    dq.push_back({j, k, i, 0});
                }
            }
        }
    }
    
    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    
    int days = 0;
    
    while(!dq.empty()){
        int px, py, pz, pt;
        tie(px, py, pz, pt) = dq.front();
        dq.pop_front();
        days = max(days, pt);
        for(int i = 0; i < 6; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];
            int nz = pz + dz[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M && 0 <= nz && nz < H && Tomato[nx][ny][nz] == 0){
                Tomato[nx][ny][nz] = 1;
                dq.push_back({nx, ny, nz, pt + 1});
            }
        }
    }
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < M; k++){
                if(Tomato[j][k][i] == 0){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    
    cout << days;
    return 0;
}