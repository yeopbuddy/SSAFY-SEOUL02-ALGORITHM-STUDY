// 문제 제목 : 오큰수
// 문제 난이도 : 골드 4
// 문제 요약 : 수열에서 현재 수보다 크면서 오른쪽에 있으면서 가장 왼쪽에 있는 수로 이루어진 수열 구하기

#include <iostream>
#include <deque>
using namespace std;
int main(){
    
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    deque<int> Nums(N);
    
    for(int i = 0; i < N; i++){
        cin >> Nums[i];
    }
    
    deque<int> Ans;
    deque<int> Stack;
    
    Ans.push_front(-1);
    Stack.push_front(Nums[N - 1]);
    
    for(int i = N - 2; i >= 0; i--){
        if(Stack[0] > Nums[i]){
            Ans.push_front(Stack[0]);
            Stack.push_front(Nums[i]);
        }else{
            while(true){
                Stack.pop_front();
                if(Stack.empty()){
                    Ans.push_front(-1);
                    Stack.push_front(Nums[i]);
                    break;
                }
                if(Stack[0] > Nums[i]){
                    Ans.push_front(Stack[0]);
                    Stack.push_front(Nums[i]);
                    break;
                }
            }
        }
    }
    
    for(int num : Ans){
        cout << num << " ";
    }
    
}