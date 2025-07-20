// 문제 제목 : 문자와 문자열
// 문제 난이도 : 브론즈 5
// 문제 요약 : 문자열과 인덱스가 주어지면, 해당 인덱스의 문자 출력

#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int idx;
    cin >> s >> idx;
    cout << s[idx - 1];
    return 0;
}