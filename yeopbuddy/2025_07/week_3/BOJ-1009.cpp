// 문제 제목 : 분산처리
// 문제 난이도 : 브론즈 2
// 문제 요약 : 큰 수에 대한 나머지 연산 구현하기

#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        
        int a, b;
        cin >> a >> b;
        
        int num = 1;
        
        for(int i = 0; i < b; i++){
            num *= a; num %= 10;
        }
        if (num == 0){
            cout << "10\n";
        }else{
            cout << num << "\n";   
        }
    }
    return 0;
}