// 문제 제목 : 코딩은 체육과목 입니다
// 문제 난이도 : 브론즈 2
// 문제 요약 : 주어진 숫자에 맞게 문자열 출력

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