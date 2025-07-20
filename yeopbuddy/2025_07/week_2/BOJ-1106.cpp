// 문제 제목 : 호텔
// 문제 난이도 : 골드 4
// 문제 요약 : 고객을 일정 수 이상으로 늘리기 위해 투자해야 하는 돈의 최솟값 구하기
#include <iostream>
#include <vector>
using namespace std;
int main(){
    
    int C, N;
    cin >> C >> N;
    
    vector<int> Invest(2001, 1e9); // Invest[i] : i명이 오도록 홍보하는 데 드는 최소 가격
    vector<vector<int>> AdverTise(N, vector<int>(2)); // [i][0] : 비용, [i][1] : 고객 수
    
    for(int i = 0; i < N; i++){
        cin >> AdverTise[i][0] >> AdverTise[i][1];
    }
    
    // 전처리 1
    for(int i = 0; i < N; i++){
        if(AdverTise[i][1] > C){ // 홍보가 필요한 고객 수보다 많은 경우 (ex. 총 10명만 홍보해도 되는데, 100명 홍보에 100원 든다고 하는 경우)
            for(int j = 1; j <= 2000; j++){ // 모든 경우에 대해서 최솟값 갱신
                Invest[j] = min(Invest[j], AdverTise[i][0]);
            }
        }else{ // 홍보가 필요한 고객 수보다 적은 경우 (ex. 총 10명 홍보해야 하는데, 2명 홍보하는데 2원 든다고 하는 경우)
            int V = AdverTise[i][0]; // 비용
            int T = AdverTise[i][1]; // 고객 수
            while(T <= 2000){
                Invest[T] = min(Invest[T], V); // 배수 형태로 증가하며 최솟값 갱신 (2명에 2원, 4명에 4원 ..)
                V += AdverTise[i][0]; 
                T += AdverTise[i][1]; 
            }
        }
    }
    
    // 전처리 2 : 더 낮은 가격으로 홍보할 수 있는 경우가 이미 있는 경우 찾기 (ex. 1명~9명까지 홍보 가격이 10원이고 10명 홍보 가격이 5원일 때, 모두 5원으로 갱신)
    int Min = Invest[2000];
    for(int i = 2000; i >= 0; i--){
        Invest[i] = min(Invest[i], Min);
        Min = Invest[i];
    }
    
    // 전처리 3 : Invest[j](j명 홍보하기 위한 최소 가격)에 대해
    // Invest[j + AdverTise[i][1]] (j + AdverTise[i][1]명 홍보하기 위한 최소 가격)과
    // Invest[j] + AdverTise[i][0] (현재 가격 + 홍보 가격)에 대한 최솟값 갱신 연산
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= 2000; j++){
            if(j + AdverTise[i][1] > 2000){
                break;
            }else{
                Invest[j + AdverTise[i][1]] = min(Invest[j + AdverTise[i][1]], Invest[j] + AdverTise[i][0]);
            }
        }
    }
    
    cout << Invest[C];
    
    return 0;
}