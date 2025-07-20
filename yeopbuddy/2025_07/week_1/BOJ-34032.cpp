// 문제 제목 : /gg
// 문제 난이도 : 브론즈 3
// 문제 요약 : O와 X 개수를 비교하여 항복 여부 출력하기
#include <iostream>
using namespace std;
int main(){
    
    int n;
    cin >> n;

    int ocnt = 0;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        if(c == 'O'){
            ocnt++;
        }
    }
    
    if(ocnt >= n - ocnt){
        cout << "Yes";
    }else{
        cout << "No";
    }
    
    
    return 0;
}