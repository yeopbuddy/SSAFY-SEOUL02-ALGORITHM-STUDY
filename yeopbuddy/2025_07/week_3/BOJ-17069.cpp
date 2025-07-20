// 문제 제목 : 파이프 옮기기 2
// 문제 난이도 : 골드 4
// 문제 요약 : 3가지 종류의 파이프를 사용해서 맵의 좌상단에서 우하단으로 이어지는 파이프의 경우의 수 찾기

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    vector<vector<int>> Obstacles(N, vector<int>(N));
    vector<vector<vector<long long>>> DP(N, vector<vector<long long>>(N, vector<long long>(3, 0)));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> Obstacles[i][j];
        }
    }
    
    DP[0][1][0] = 1;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(DP[i][j][0] != 0){
                if (j + 1 < N && Obstacles[i][j + 1] == 0) {
                    DP[i][j + 1][0] += DP[i][j][0];
                }
                if (i + 1 < N && j + 1 < N && (Obstacles[i][j + 1] + Obstacles[i + 1][j] + Obstacles[i + 1][j + 1]) == 0) {
                    DP[i + 1][j + 1][2] += DP[i][j][0];
                }
            }
            if(DP[i][j][1] != 0){
                if (i + 1 < N && Obstacles[i + 1][j] == 0) {
                    DP[i + 1][j][1] += DP[i][j][1];
                }
                if (i + 1 < N && j + 1 < N && (Obstacles[i][j + 1] + Obstacles[i + 1][j] + Obstacles[i + 1][j + 1]) == 0) {
                    DP[i + 1][j + 1][2] += DP[i][j][1];
                }
            }
            if(DP[i][j][2] != 0){
                if (j + 1 < N && Obstacles[i][j + 1] == 0) {
                    DP[i][j + 1][0] += DP[i][j][2];
                }
                if (i + 1 < N && Obstacles[i + 1][j] == 0) {
                    DP[i + 1][j][1] += DP[i][j][2];
                }
                if (i + 1 < N && j + 1 < N && (Obstacles[i][j + 1] + Obstacles[i + 1][j] + Obstacles[i + 1][j + 1]) == 0) {
                    DP[i + 1][j + 1][2] += DP[i][j][2];
                }
            }
            
        }
    }
    
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << DP[i][j][0] + DP[i][j][1] + DP[i][j][2] << " ";
    //     }
    //     cout << "\n";
    // }
    
    
    cout << DP[N - 1][N - 1][0] + DP[N - 1][N - 1][1] + DP[N - 1][N - 1][2];
}