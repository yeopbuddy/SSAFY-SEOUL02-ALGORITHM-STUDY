// 문제 제목 : 다이어트
// 문제 난이도 : 골드 5
// 문제 요약 : 주어진 수를 직각삼각형의 빗변이 아닌 한 변의 제곱이라고 가정했을 때, 가능한 빗변의 길이들 출력
#include <iostream>
using namespace std;
int main(){
    
    int g;
    cin >> g;
    
    int c = 1;
    int b = 1;
    
    bool nope = false;
    
    while(c <= 100000){
        int a = c * c - b * b;
        if(a == g){
            nope = true;
            cout << c << "\n";
            c++; b++;
        }else{
            if(g > a){
                c++;
            }else{
                b++;
            }
        }
    }
    
    if(!nope){
        cout << "-1";
    }
    
    return 0;
}