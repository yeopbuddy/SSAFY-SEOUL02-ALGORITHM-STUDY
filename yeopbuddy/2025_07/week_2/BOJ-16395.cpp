// 문제 제목 : 파스칼의 삼각형
// 문제 난이도 : 실버 5
// 문제 요약 : 행과 열이 주어지면 파스칼의 삼각형에서 그 요소 출력

#include <iostream>
using namespace std;
int main(){
    
    int n, k;
    cin >> n >> k;
    
    int arr[31][31] = {0};
    
    for(int i = 0; i < 31; i++){
        arr[i][0] = 1; arr[i][i] = 1;
    }
    
    for(int i = 1; i < 31; i++){
        for(int j = 1; j < 31; j++){
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    
    cout << arr[n - 1][k - 1];
    return 0;
}