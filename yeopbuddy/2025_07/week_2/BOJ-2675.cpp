// 문제 제목 : 문자열 반복
// 문제 난이도 : 브론즈 2
// 문제 요약 : 주어진 문자열 정해진 만큼 반복해서 출력하기

#include <iostream>
#include <string>
using namespace std;
int main(){
    
    int TC;
    cin >> TC;

    for(int tc = 0; tc < TC; tc++){
        int n; string s;
        cin >> n >> s;
        for(char c : s){
            for(int j = 0; j < n; j++){
                cout << c;
            }
        }
        cout << "\n";
    }

    return 0;
}