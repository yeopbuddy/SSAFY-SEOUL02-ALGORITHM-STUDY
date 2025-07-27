#include <iostream>
using namespace std;

const int MX = 10000;

int N;
char arr[MX][MX];

void solution(int sx, int sy, int ex, int ey){

	// cout << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';

	if(ey-sy==3 && ex-sx==3){
		for(int i=sx; i<ex; i++){
			for(int j=sy; j<ey; j++){
				if(i == (ex+sx)/2 && j == (ey+sy)/2) continue;
				arr[i][j] = '*';
			}
		}
		return;
	}


	int mx = (ex - sx) / 3;
	int my = (ey - sy) / 3;

	// cout << mx << ' ' << my << '\n';
	

	solution(sx, sy, sx+mx, sy+my);
	solution(sx, sy+my, sx+mx, sy+my*2);
	solution(sx, sy+my*2, sx+mx, ey);

	solution(sx+mx, sy, sx+mx*2, sy+my);

	solution(sx+mx, sy+my*2, sx+mx*2, ey);

	solution(sx+mx*2, sy, ex, sy+my);
	solution(sx+mx*2, sy+my, ex, sy+my*2);
	solution(sx+mx*2, sy+my*2, ex, ey);
}

int main() {
	cin >> N;

	solution(0, 0, N, N);

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == '*'){
				cout << arr[i][j];
			}
			else{
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}