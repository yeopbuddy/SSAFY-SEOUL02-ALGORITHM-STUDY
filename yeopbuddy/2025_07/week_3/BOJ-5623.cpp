// 문제 제목 : 수열의 합
// 문제 난이도 : 실버 4
// 문제 요약 : 주어진 수열들에서의 수학적 규칙을 찾아 원래 수열 출력

#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    vector<vector<int>> Sequence(N, vector<int>(N + 1));
    
    long long SeqSum = 0;
    
    for(int i = 0; i < N; i++){
        int LineSum = 0;
        for(int j = 0; j < N; j++){
            cin >> Sequence[i][j];
            SeqSum += Sequence[i][j];
            LineSum += Sequence[i][j];
        }
        Sequence[i][N] = LineSum;
    }
    
    SeqSum /= (2*N - 2);
    
    if(N == 2){
        cout << "1 " << SeqSum - 1;
    }else{
        for(int i = 0; i < N; i++){
            cout << (Sequence[i][N] - SeqSum) / (N - 2) << " ";
        }
    }
    
    return 0;
}