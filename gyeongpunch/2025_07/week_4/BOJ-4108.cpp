#include <iostream>
using namespace std;

const int MX = 100;

int N, M;

char arr[MX][MX];
char result[MX][MX];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<M;
}

char get_point(int x, int y){
	int cnt = 0;
	for(int i=0; i<8; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(!bound_check(nx, ny)) continue;
		if(arr[nx][ny] != '*') continue;

		cnt++;
	}
	return (char)(cnt+'0');
}

void solution(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == '*'){
				result[i][j] = '*';
			}
			else{
				result[i][j] = get_point(i, j);
			}
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << result[i][j]; 
		}
		cout << '\n';
	}
}

int main() {
	while(true){
		cin >> N >> M;
		if(N==0 && M==0){
			break;
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> arr[i][j];
			}
		}

		solution();
	}
	return 0;
}