// 문제 제목 : 알고스팟
// 문제 난이도 : 골드 4
// 문제 요약 : 좌측 상단부터 우측 하단까지 벽을 최소로 부수면서 이동하는 경우 찾기

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int main(){
    
    int N, M;
    cin >> N >> M;

    vector<vector<char>> Algo(M, vector<char>(N));
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> Algo[i][j];
        }
    }

    vector<vector<int>> MinStep(M, vector<int>(N, 1e9));
    
    deque<tuple<int, int, int>> dq;
    dq.push_back({0,0,0});
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
    while(!dq.empty()){
        int px, py, ps;
        tie(px, py, ps) = dq.front();
        dq.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = px + dx[i];
            int ny = py + dy[i];
            if(0 <= nx && nx < M && 0 <= ny && ny < N){
                if(Algo[nx][ny] == '1' && MinStep[nx][ny] > ps + 1){
                    MinStep[nx][ny] = ps + 1;
                    dq.push_back({nx, ny, ps + 1});
                }
                else if(Algo[nx][ny] == '0' && MinStep[nx][ny] > ps){
                    MinStep[nx][ny] = ps;
                    dq.push_back({nx, ny, ps});
                }
            }
        }
    }
    if(N == 1 && M == 1){
        cout << "0";
    }else{
        cout << MinStep[M - 1][N - 1];   
    }
    return 0;
}