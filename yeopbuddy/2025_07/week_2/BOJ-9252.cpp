// 문제 제목 : LCS 2
// 문제 난이도 : 골드 4
// 문제 요약 : 가장 긴 공통 부분 문자열과 그 길이 출력하기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    
    int Ans = 0;
    string s1, s2;
    cin >> s1 >> s2;
    
    int s1s = s1.size();
    int s2s = s2.size();
    
    vector<vector<int>> DP(s1s, vector<int>(s2s, 0));
    
    // 전처리
    for(int i = 0; i < s1s; i++){
        for(int j = 0; j < s2s; j++){
            if(s1[i] == s2[j]){
                DP[i][j] = 1;
            }
        }
    }
    
    // 계산
    for(int i = 0; i < s1s; i++){
        for(int j = 0; j < s2s; j++){
            if(DP[i][j] == 1){
                if(i > 0 && j > 0){
                    DP[i][j] += DP[i - 1][j - 1];
                }
            }else{
                if(i > 0){
                    DP[i][j] = max(0, DP[i - 1][j]);
                }
                if(j > 0){
                    DP[i][j] = max(DP[i][j], DP[i][j - 1]);
                }
            }
            Ans = max(Ans, DP[i][j]);
        }
    }
    
    // 역추적
    string ans = "";
    int x = s1s - 1;
    int y = s2s - 1;
    while(true){
        if(x > 0 && y > 0){
            int C = DP[x][y];
            int L = DP[x][y - 1];
            int U = DP[x - 1][y];
            if(C == L){
                --y;
            }else if(C == U){
                --x;
            }else{
                ans += s1[x];
                if(DP[x][y] == 1){
                    break;
                } --x;
            }
        }else if(x > 0){
            int C = DP[x][y];
            int U = DP[x - 1][y];
            if(C == U){
                --x;
            }else{
                ans += s1[x];
                if(DP[x][y] == 1){
                    break;
                }--x;
            }
        }else if(y > 0){
            int C = DP[x][y];
            int L = DP[x][y - 1];
            if(C == L){
                --y;
            }else{
                ans += s1[x];
                if(DP[x][y] == 1){
                    break;
                }--y;
            }
        }else{
            if(DP[x][y] == 1){
                ans += s1[x];   
            }
            break;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << Ans << "\n" << ans;
    
    return 0;
}