#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

struct Point{
	int x, y;
};

const int MX = 100;

int N;
int arr[MX][MX];
int visited[MX][MX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int result = INT_MAX;

int tmp[MX][MX];

bool bound_check(int x, int y){
	return 0<=x && x<N && 0<=y && y<N;
}

void bfs1(int x, int y, int num){
	queue<Point> q;
	q.push({x, y});
	visited[x][y] = num;

	while(!q.empty()){
		Point now = q.front(); q.pop();

		for(int i=0; i<4; i++){
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if(!bound_check(nx, ny)) continue;
			if(visited[nx][ny] != 0) continue;
			if(arr[nx][ny] == 0) continue;

			q.push({nx, ny});
			visited[nx][ny] = num;
		}
	}
}

void bfs2(int x, int y){
	memset(tmp, 0, sizeof(tmp));
	queue<Point> q;
	q.push({x, y});
	tmp[x][y] = 1;
	
	while(!q.empty()){
		Point now = q.front(); q.pop();

		for(int i=0; i<4; i++){
			int nx = now.x+dx[i];
			int ny = now.y+dy[i];

			if(!bound_check(nx, ny)) continue;
			if(tmp[nx][ny] != 0) continue;

			if(arr[nx][ny] == 1){
				if(visited[nx][ny] != visited[x][y]){
					result = min(result, tmp[now.x][now.y]-1);
					return;
				}
			}
			else{
				q.push({nx, ny});
				tmp[nx][ny] = tmp[now.x][now.y] + 1;
			}

			
		}
	}
}

int main() {
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> arr[i][j];
		}
	}

	int cnt = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] != 0 && visited[i][j] == 0){
				bfs1(i, j, cnt);
				cnt++;
			}
		}
	}

	// for(int i=0; i<N; i++){
	// 	for(int j=0; j<N; j++){
	// 		cout << visited[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(arr[i][j] == 1){
				bfs2(i, j);
			}
		}
	}

	cout << result << '\n';

	return 0;
}