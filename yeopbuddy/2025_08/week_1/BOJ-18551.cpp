// 문제 제목 : 큰 수 구성하기
// 문제 난이도 : 실버 5
// 문제 요약 : 타겟 숫자와 요소 숫자들이 주어졌을 때, 요소 숫자들을 이용해 타겟 숫자보다 작은 수 중 가장 큰 수 구성하기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    
    int N, K;
    cin >> N >> K;
    
    vector<int> Nums;
    vector<int> knums(K);
    
    for(int i = 0; i < K; i++){
        cin >> knums[i];
        Nums.push_back(knums[i]);
    }

    // 2 ~ 8자리의 knums의 원소로 이루어진 숫자들 생성 및 저장
    
    for(int i = 0; i < K; i++){ // 2자리
        for(int j = 0; j < K; j++){
            int num = 10 * knums[i] + knums[j];
            Nums.push_back(num);
        }
    }
    
    for(int i = 0; i < K; i++){ // 3자리
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                int num = 100 * knums[i] + 10 * knums[j] + knums[k];
                Nums.push_back(num);   
            }
        }
    }
    
    for(int i = 0; i < K; i++){ // 4자리
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                for(int l = 0; l < K; l++){
                    int num = 1000 * knums[i] + 100 * knums[j] + 10 * knums[k] + knums[l];
                    Nums.push_back(num);      
                }
            }
        }
    }
    
    for(int i = 0; i < K; i++){ // 5자리
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                for(int l = 0; l < K; l++){
                    for(int m = 0; m < K; m++){
                        int num = 10000 * knums[i] + 1000 * knums[j] + 100 * knums[k] + 10 * knums[l] + knums[m];
                        Nums.push_back(num);         
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < K; i++){ // 6자리
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                for(int l = 0; l < K; l++){
                    for(int m = 0; m < K; m++){
                        for(int n = 0; n < K; n++){
                            int num = 100000 * knums[i] + 10000 * knums[j] + 1000 * knums[k] + 100 * knums[l] + 10 * knums[m] + knums[n];
                            Nums.push_back(num);            
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < K; i++){ // 7자리
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                for(int l = 0; l < K; l++){
                    for(int m = 0; m < K; m++){
                        for(int n = 0; n < K; n++){
                            for(int o = 0; o < K; o++){
                                int num = 1000000 * knums[i] + 100000 * knums[j] + 10000 * knums[k] + 1000 * knums[l] + 100 * knums[m] + 10 * knums[n] + knums[o];
                                Nums.push_back(num);               
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < K; i++){ // 8자리
        for(int j = 0; j < K; j++){
            for(int k = 0; k < K; k++){
                for(int l = 0; l < K; l++){
                    for(int m = 0; m < K; m++){
                        for(int n = 0; n < K; n++){
                            for(int o = 0; o < K; o++){
                                for(int p = 0; p < K; p++){
                                    int num = 10000000 * knums[i] + 1000000 * knums[j] + 100000 * knums[k] + 10000 * knums[l] + 1000 * knums[m] + 100 * knums[n] + 10 * knums[o] + knums[p];
                                    Nums.push_back(num);               
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    sort(Nums.begin(), Nums.end());
    bool find = false;
    for(int i = 0; i < Nums.size(); i++){
        if(Nums[i] > N){
            cout << Nums[i - 1];
            find = true;
            break;
        }
    }
    if(!find){
        cout << Nums[Nums.size() - 1];
    }
    return 0;
}