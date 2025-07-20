// 문제 제목 : 최댓값
// 문제 난이도 : 브론즈 3
// 문제 요약 : 주어진 9개의 수 중 가장 큰 수와 그 인덱스 찾기

#include <iostream>
using namespace std;
int main(){
    int mnum = -1;
    int midx = -1;
    
    for(int i = 0; i < 9; i++){
        int num;
        cin >> num;
        if(num > mnum){
            mnum = num;
            midx = i + 1;
        }
    }
    
    cout << mnum << "\n" << midx;
    
    return 0;
}