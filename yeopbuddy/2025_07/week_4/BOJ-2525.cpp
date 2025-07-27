// 문제 제목 : 오븐 시계
// 문제 난이도 : 브론즈 3
// 문제 요약 : 시간과 분, 소요 시간이 주어질 경우 끝나는 시간 출력하기

#include <iostream>
using namespace std;
int main(){
    int h, m, c;
    cin >> h >> m >> c;
    
    m += c;
    if(m >= 60){
        h += (m / 60);
        m %= 60;
    }
    if(h > 23){
        h %= 24;
    }
    
    cout << h << " " << m;

    return 0;
}