// 문제 제목 : 숨바꼭질
// 문제 난이도 : 실버 1
// 문제 요약 : 1차원 BFS

#include <iostream>
#include <deque>
using namespace std;

bool visit[100001];

int main(){
    
    int N, K;
    cin >> N >> K;
    
    deque<pair<int, int>> dq;
    dq.push_back({N, 0});
    
    while(!dq.empty()){
        int pn = dq.front().first;
        int pt = dq.front().second;
        
        if(pn == K){
            cout << pt;
            break;
        }
        
        dq.pop_front();
        
        if(pn - 1 >= 0 && !visit[pn - 1]){
            visit[pn - 1] = true;
            dq.push_back({pn - 1, pt + 1});
        }
        
        if(pn + 1 <= 100000 && !visit[pn + 1]){
            visit[pn + 1] = true;
            dq.push_back({pn + 1, pt + 1});
        }
        if( 2 * pn <= 100000 && !visit[2 * pn]){
            visit[2 * pn] = true;
            dq.push_back({2 * pn, pt + 1});
        }
        
    }
    
}