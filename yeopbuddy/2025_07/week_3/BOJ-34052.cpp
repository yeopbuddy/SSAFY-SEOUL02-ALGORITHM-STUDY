// 문제 제목 : 체육은 수학과목 입니다2
// 문제 난이도 : 브론즈 5
// 문제 요약 : 주어진 4개의 숫자의 합이 1500 이하인지 판단

#include <iostream>
using namespace std;
int main(){
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if(a + b + c + d <= 1500){
        cout << "Yes";
    }else{
        cout << "No";
    }
    

    return 0;
}