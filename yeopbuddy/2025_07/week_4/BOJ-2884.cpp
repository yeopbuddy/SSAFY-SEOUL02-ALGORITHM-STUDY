// 문제 제목 : 알람 시계
// 문제 난이도 : 브론즈 3
// 문제 요약 : 시간과 분이 주어지면, 45분 당긴 시간과 분 출력하기

#include <iostream>
using namespace std;
int main(){
    
    int H, M;
    cin >> H >> M;

    M -= 45;
    
    if(M < 0){
        M += 60;
        H += 23;
        H %= 24;
    }
        
    cout << H << " " << M;

    return 0;
}