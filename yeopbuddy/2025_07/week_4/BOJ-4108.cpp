// 문제 제목 : 지뢰찾기
// 문제 난이도 : 실버 5
// 문제 요약 : 지도가 주어지면 주변 8개 영역의 지뢰의 개수 출력하기

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int R, C;
    int dx[8] = {-1,0,1,-1,1,-1,0,1};
    int dy[8] = {-1,-1,-1,0,0,1,1,1};
    while(cin >> R >> C){
        if(R == 0 && C == 0){
            break;
        }
        vector<vector<char>> MineMap(R, vector<char>(C));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> MineMap[i][j];
            }
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(MineMap[i][j] == '*'){
                    cout << '*';
                }else{
                    int cnt = 0;
                    for(int k = 0; k < 8; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(0 <= nx && nx < R && 0 <= ny && ny < C && MineMap[nx][ny] == '*'){
                            cnt++;
                        }
                    }
                    cout << cnt;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}