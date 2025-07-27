#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

struct Point{
	int x, y;
};

const int N = 9;

int arr[N][N];

unordered_set<int> garo[N+1];
unordered_set<int> sero[N+1];
unordered_set<int> diag[N+1];

vector<Point> Emp;
bool resultFlag = false;

void print_result(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << arr[i][j];
		}
		cout << '\n';
	}
}

void dfs(int depth){
	// print_result();
	// cout << "\n\n";

	if(resultFlag){
		return;
	}

	if(depth == Emp.size()){
		print_result();
		resultFlag = true;
		return;
	}

	Point now = Emp[depth];

	for(int i=1; i<=9; i++){
		if(garo[now.x].find(i) != garo[now.x].end()) continue;
		if(sero[now.y].find(i) != sero[now.y].end()) continue;
		int idx = 3*(now.x/3) + (now.y/3);
		if(diag[idx].find(i) != diag[idx].end()) continue;

		garo[now.x].insert(i);
		sero[now.y].insert(i);
		diag[idx].insert(i);
		arr[now.x][now.y] = i;

		dfs(depth + 1);

		garo[now.x].erase(i);
		sero[now.y].erase(i);
		diag[idx].erase(i);
		arr[now.x][now.y] = 0;
	}
}

int main() {

	string s;
	for(int i=0; i<N; i++){
		cin >> s;
		for(int j=0; j<N; j++){
			arr[i][j] = s[j] - '0';
			int idx = 3*(i/3) + (j/3);
			if(arr[i][j] != 0){
				garo[i].insert(arr[i][j]);
				sero[j].insert(arr[i][j]);
				diag[idx].insert(arr[i][j]);
			}
			else{
				Emp.push_back({i, j});
			}
		}
	}

	// for(Point p : Emp){
	// 	cout << p.x << ' ' << p.y << '\n';
	// }

	dfs(0);

	return 0;
}

/*
0,0 -> 0
0,1 -> 0
0,2 -> 0

0,3 -> 1
0,4 -> 1
0,5 -> 1

3,0 -> 3
3,1 -> 3
3,2 -> 3

3,3 -> 4
3,4 -> 4
3,5 -> 4

*/