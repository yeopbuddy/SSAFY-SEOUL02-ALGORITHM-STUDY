// 문제 제목 : 사파리월드
// 문제 난이도 : 브론즈 5
// 문제 요약 : 주어진 두 수의 차이의 절댓값 구하기

#include <iostream>
using namespace std;
int main(){
    long long a, b;
    cin >> a >> b;
    a -= b;
    if(a < 0){
        cout << -a;
    }else{
        cout << a;
    }
}