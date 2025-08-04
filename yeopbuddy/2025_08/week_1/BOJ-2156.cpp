// 문제 제목 : 포도주 시식
// 문제 난이도 : 실버 1
// 문제 요약 : 3개 연속으로 선택하지 않으면서 선택한 수의 합이 최대가 되도록 하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> grape(2, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        cin >> grape[0][i];
        if(i >= 1){
            grape[1][i] = grape[0][i] + grape[0][i - 1];
        }
    }
    int Max = 0;
    for(int i = 0; i < n; i++){
        if(i >= 4){
            grape[0][i] += max(max(grape[0][i - 2], grape[1][i - 2]), max(grape[0][i - 3], grape[1][i - 3]));
            grape[1][i] += max(max(grape[0][i - 3], grape[1][i - 3]), max(grape[0][i - 4], grape[1][i - 4]));
        }else if(i >= 3){
            grape[0][i] += max(max(grape[0][i - 2], grape[1][i - 2]), max(grape[0][i - 3], grape[1][i - 3]));
            grape[1][i] += max(grape[1][i - 3], grape[0][i - 3]);
        }else if(i >= 2){
            grape[0][i] += max(grape[0][i - 2], grape[1][i - 2]);
        }
        Max = max(Max, grape[0][i]); Max = max(Max, grape[1][i]);
    }
    cout << Max;
    return 0;
}