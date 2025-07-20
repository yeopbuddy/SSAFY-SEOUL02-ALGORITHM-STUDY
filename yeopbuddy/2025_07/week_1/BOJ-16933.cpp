// 문제 제목 : 벽 부수고 이동하기 3
// 문제 난이도 : 골드 1
// 문제 요약 : 이동할 수 있는 조건이 정해져 있을 때의 2차원 BFS

#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> ArrayMap(n, vector<char>(m));
    // vector<vector<pair<int, int>>> ArrayStatus(n, vector<pair<int, int>>(m)); // 부셨을 때 경로 길이, 안부셨을 때 경로 길이
    vector<vector<vector<int>>> ArrayStatus(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ArrayMap[i][j];
        }
    }
    if(ArrayMap[0][0] == '1' || ArrayMap[n - 1][m - 1] == '1'){
        cout << "-1";
    }
    else{
        if(n == 1 && m == 1){
            cout << "1";
        }
        else{
            deque<tuple<int, int, int, int>> dq; // x, y, break, dis
            dq.push_back({0,0,0, 1});
            int dx[5] = {0,0,1,-1};
            int dy[5] = {1,-1,0,0};
            while(!dq.empty()){
                int px, py, pb, pd;
                tie(px, py, pb, pd) = dq.front();
                dq.pop_front();
                for(int i = 0; i < 4; i++){
                    int nx = px + dx[i];
                    int ny = py + dy[i];
                    // 부시고 일찍 간거 vs 안부시고 늦게 간거
                    if((0 <= nx && nx < n) && (0 <= ny && ny < m)){
                        if(ArrayMap[nx][ny] == '0' && (ArrayStatus[nx][ny][pb] == -1 || ArrayStatus[nx][ny][pb] > pd + 1)){
                            ArrayStatus[nx][ny][pb] = pd + 1;
                            dq.push_back({nx, ny, pb, pd + 1});
                        }else if(ArrayMap[nx][ny] == '1' && pb + 1 <= k && (ArrayStatus[nx][ny][pb + 1] == -1 || ArrayStatus[nx][ny][pb + 1] > pd + 1)){
                          if(pd % 2 == 1){
                            ArrayStatus[nx][ny][pb + 1] = pd + 1;
                            dq.push_back({nx, ny, pb + 1, pd + 1});
                          }else{
                            // ArrayStatus[px][py][pb] = pd + 1;
                            dq.push_back({px, py, pb, pd + 1});
                          }
                            
                        }
                    }
                }
            }
            
            bool findPath = false;
            int PathLen = -1;
            
            for(int l = 0; l <= k; l++){
                if(ArrayStatus[n-1][m-1][l] != -1){
                    if(!findPath){
                        findPath = true;
                        PathLen = ArrayStatus[n-1][m-1][l];
                    }else{
                        PathLen = min(PathLen, ArrayStatus[n-1][m-1][l]);
                    }
                }
            }
            cout << PathLen;
        }
    }
    return 0;
}