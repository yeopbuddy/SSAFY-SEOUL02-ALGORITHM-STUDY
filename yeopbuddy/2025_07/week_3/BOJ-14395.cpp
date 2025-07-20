// 문제 제목 : 4연산
// 문제 난이도 : 골드 4
// 문제 요약 : 4가지 연산(현재 수 2배, 현재 수 제곱, 현재 수 0으로 만들기, 현재 수 1로 만들기)사용해서 숫자 변환하는 최소 연산 횟수 구하기

#include <iostream>
#include <deque>
#include <map>
#include <tuple>
#include <string>

using namespace std;

int main(){
    
    long long S, T;
    cin >> S >> T;
    
    
    deque<tuple<long long, long long, string>> dq;
    dq.push_back({S, 0, ""});
    
    map<long long, long long> Map;
    
    while(!dq.empty()){
        long long ps, pt; 
        string po;
        tie(ps, pt, po) = dq.front();
        dq.pop_front();
        
        if(ps == T){
            if(pt == 0){
                cout << "0";
            }else{
                cout << po;
            }
            return 0;
        }
        
        if (ps * ps <= 1e10 && Map.find(ps * ps) == Map.end()){
            Map[ps * ps] = pt + 1;
            dq.push_back({ps * ps, pt + 1, po + '*'});
        }
        if(ps + ps <= 1e10 && Map.find(ps + ps) == Map.end()){
            Map[ps + ps] = pt + 1;
            dq.push_back({ps + ps, pt + 1, po + '+'});
        }
        if(Map.find(ps - ps) == Map.end()){
            Map[ps - ps] = pt + 1;
            dq.push_back({ps - ps, pt + 1, po + '-'});
        }
        if(ps != 0 && Map.find(ps / ps) == Map.end()){
            Map[ps / ps] = pt + 1;
            dq.push_back({ps / ps, pt + 1, po + '/'});
        }
        
    }
    cout << "-1";
    
    return 0;
}