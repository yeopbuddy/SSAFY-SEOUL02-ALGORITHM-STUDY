// 문제 제목 : 스택
// 문제 난이도 : 실버 4
// 문제 요약 : 스택 자료구조 구현하기

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<int> Stack;
    
    for(int i = 0; i < N; i++){
        string cmd; int num;
        
        cin >> cmd;
        
        if(cmd == "push"){
            cin >> num;
            Stack.push_back(num);
        }else if(cmd == "top"){
            if(!Stack.empty()){
                cout << Stack[Stack.size() - 1] << "\n";
            }else{
                cout << "-1\n";
            }
        }else if(cmd == "pop"){
            if(!Stack.empty()){
                cout << Stack[Stack.size() - 1] << "\n";
                Stack.pop_back();
            }else{
                cout << "-1\n";
            }
        }else if(cmd == "size"){
            cout << Stack.size() << "\n";
        }else if(cmd == "empty"){
            if(!Stack.empty()){
                cout << "0\n";
            }else{
                cout << "1\n";
            }
        }
    }
    
    return 0;
}