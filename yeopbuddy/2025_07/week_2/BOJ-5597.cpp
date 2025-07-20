// 문제 제목 : 과제 안 내신 분..? 
// 문제 난이도 : 브론즈 3
// 문제 요약 : 1~30까지 주어지지 않은 번호 찾기

#include <iostream>
#include <vector>
using namespace std;

bool attend[30];

int main(){
    for(int i = 0; i < 28; i++){
        int num; cin >> num;
        attend[--num] = true;
    }
    for(int i = 0; i < 30; i++){
        if(!attend[i]){
            cout << i + 1 << "\n";
        }
    }
}