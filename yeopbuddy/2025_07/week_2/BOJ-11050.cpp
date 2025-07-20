// 문제 제목 : 이항 계수 1
// 문제 난이도 : 브론즈 1
// 문제 요약 : Combination 연산 구현
#include <iostream>
using namespace std;
int main(){
    
    int n, k;
    cin >> n >> k;
    
    int num = 1;
    
    for(int i = 2; i <= n; i++){
        num *= i;
    }

    for(int i = 2; i <= k; i++){
        num /= i;
    }

    for(int i = 2; i <= n - k; i++){
        num /= i;
    }

    cout << num;

    return 0;
}