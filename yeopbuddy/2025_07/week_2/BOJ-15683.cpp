// 문제 제목 : 감시
// 문제 난이도 : 골드 3
// 문제 요약 : CCTV를 회전했을 때, 가장 많이 감시할 수 있는 영역 찾기
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> CCTVMAP;

vector<tuple<int, int, int>> CCTV; // x, y, CCTV 종류

int Ans = 64;

int Eval(){
    
    int cnt = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(CCTVMAP[i][j] == 0){
                cnt++;
            }
        }
    }
    
    return cnt;
}

void UP(int x, int y){
    --x;
    while(x >= 0){
        if(CCTVMAP[x][y] == 6) return;
        else if(CCTVMAP[x][y] == 0) CCTVMAP[x][y] = -1;
        --x;
    }
}
void LEFT(int x, int y){
    --y;
    while(y >= 0){
        if(CCTVMAP[x][y] == 6) return;
        else if(CCTVMAP[x][y] == 0) CCTVMAP[x][y] = -1;
        --y;
    }
}
void RIGHT(int x, int y){
    ++y;
    while(y < M){
        if(CCTVMAP[x][y] == 6) return;
        else if(CCTVMAP[x][y] == 0) CCTVMAP[x][y] = -1;
        ++y;
    }
}
void DOWN(int x, int y){
    ++x;
    while(x < N){
        if(CCTVMAP[x][y] == 6) return;
        else if(CCTVMAP[x][y] == 0) CCTVMAP[x][y] = -1;
        ++x;
    }
}
void TV1(int x, int y, int d){
    if(d == 1){
        LEFT(x, y);
    }else if(d == 2){
        DOWN(x, y);
    }else if(d == 3){
        RIGHT(x, y);
    }else{
        UP(x, y);
    }
}
void TV2(int x, int y, int d){
    if(d == 1){
        LEFT(x, y); RIGHT(x, y);
        
    }else{
        DOWN(x, y); UP(x, y);
    }
}
void TV3(int x, int y, int d){
    if(d == 1){
        UP(x, y); RIGHT(x, y);
    }else if(d == 2){
        RIGHT(x, y); DOWN(x, y);
    }else if(d == 3){
        DOWN(x, y); LEFT(x, y);
    }else{
        LEFT(x, y); UP(x, y);
    }
}
void TV4(int x, int y, int d){
    if(d == 1){
        LEFT(x, y); UP(x, y); RIGHT(x, y);
    }else if(d == 2){
        UP(x, y); RIGHT(x, y); DOWN(x, y);
    }else if(d == 3){
        RIGHT(x, y); DOWN(x, y); LEFT(x, y);
    }else{
        DOWN(x, y); LEFT(x, y); UP(x, y);
    }
}
void TV5(int x, int y){
    UP(x, y); RIGHT(x, y); DOWN(x, y); LEFT(x, y);
}

void DFS(int depth, int limit){
    if(depth == limit){
        Ans = min(Ans, Eval());
        return;
    }
    
    int C_CC_X, C_CC_Y, C_CC_I;
    tie(C_CC_X, C_CC_Y, C_CC_I) = CCTV[depth];
    
    vector<vector<int>> BACKTRACKING = CCTVMAP;
    
    switch(C_CC_I){
        case 1:{
            for(int i = 0; i < 4; i++){
                TV1(C_CC_X, C_CC_Y, i);
                DFS(depth + 1, limit);
                CCTVMAP = BACKTRACKING;
            }
            break;
        }
        case 2:{
            for(int i = 0; i < 2; i++){
                TV2(C_CC_X, C_CC_Y, i);
                DFS(depth + 1, limit);
                CCTVMAP = BACKTRACKING;
            }
            break;
        }
        case 3:{
            for(int i = 0; i < 4; i++){
                TV3(C_CC_X, C_CC_Y, i);
                DFS(depth + 1, limit);
                CCTVMAP = BACKTRACKING;
            }
            break;
        }
        case 4:{
            for(int i = 0; i < 4; i++){
                TV4(C_CC_X, C_CC_Y, i);
                DFS(depth + 1, limit);
                CCTVMAP = BACKTRACKING;
            }
            break;
        }
        case 5:{
            TV5(C_CC_X, C_CC_Y);
            DFS(depth + 1, limit);
            CCTVMAP = BACKTRACKING;
            break;
        }
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> N >> M;
    
    CCTVMAP.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> CCTVMAP[i][j];
            if(CCTVMAP[i][j] != 0 && CCTVMAP[i][j] != 6){
                CCTV.push_back({i, j, CCTVMAP[i][j]});
            }
        }
    }
    
    DFS(0, CCTV.size());
    
    cout << Ans;
}