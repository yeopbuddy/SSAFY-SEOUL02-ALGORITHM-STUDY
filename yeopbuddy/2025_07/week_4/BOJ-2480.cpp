// 문제 제목 : 주사위 세개
// 문제 난이도 : 브론즈 4
// 문제 요약 : 주어진 3개의 주사위 눈에 대해 점수 출력하기

#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b && b==c){
        cout << 10000 + 1000*a;
        }else if(a== b || a == c){
        cout << 1000 + 100*a;
        }else if(b==c){
        cout << 1000 + 100*b;
        }else{
        cout << 100 * max(a, max(b, c));
        }
}