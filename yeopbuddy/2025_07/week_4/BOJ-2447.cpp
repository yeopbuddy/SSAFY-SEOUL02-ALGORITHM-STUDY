// 문제 제목 : 별 찍기 - 10
// 문제 난이도 : 골드 5
// 문제 요약 : 주어진 규칙에 따라 별 출력하기

#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> Unit(3, vector<char>(3, '*'));

vector<vector<char>> Stars;

void GetStar(int level, int end){
    if(level == end - 1){
        int Us = Unit.size();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int a = 0; a < Us; a++){
                    for(int b = 0; b < Us; b++){
                        if(i == 1 && j == 1){
                            Stars[Us*i + a][Us*j + b] = ' ';
                        }else{
                            Stars[Us*i + a][Us*j + b] = Unit[a][b];    
                        }
                    }    
                }
            }
        }
        return;
    }else{
        int Us = Unit.size();
        int NUs = Unit.size() * 3;
        vector<vector<char>> SubUnit(NUs, vector<char>(NUs));
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int a = 0; a < Us; a++){
                    for(int b = 0; b < Us; b++){
                        if(i == 1 && j == 1){
                            SubUnit[Us*i + a][Us*j + b] = ' ';
                        }else{
                            SubUnit[Us*i + a][Us*j + b] = Unit[a][b];    
                        }
                    }    
                }
            }
        }
        Unit.clear();
        Unit = SubUnit;
        GetStar(level + 1, end);
    }
}

int main(){
    Unit[1][1] = ' ';
    int n, m;
    cin >> n;
    m = n;
    int k = 0;
    while(n != 1){
        k++; n/=3;
    }
    if(k == 1){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j <3; j++){
                cout << Unit[i][j];
            }
            cout << "\n";
        }
    }else{
        Stars.resize(m, vector<char>(m));
        GetStar(1, k);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cout << Stars[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}