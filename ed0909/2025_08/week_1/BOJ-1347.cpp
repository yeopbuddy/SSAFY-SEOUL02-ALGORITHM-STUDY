#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	vector<vector<char>>map(101, vector<char>(101, '#'));
	int n;
	string way;
	cin >> n >> way;
	int dy[4] = { 1,0,-1,0 };
	int dx[4] = { 0,-1,0,1 };
	int y = 50, x = 50;
	int xmin = x, xmax = x, ymin = y, ymax = y;
	int order_num = 0;
	map[y][x] = '.';
	for (int i = 0; i < n; i++) {
		if (way[i] == 'R') order_num = (order_num + 1) % 4;
		else if (way[i] == 'L') order_num = (order_num + 3) % 4;
		else if (way[i] == 'F') {
			x += dx[order_num];
			y += dy[order_num];
			map[y][x] = '.';
			if (xmin > x)xmin = x;
			if (xmax < x)xmax = x;
			if (ymin > y)ymin = y;
			if (ymax < y)ymax = y;
		}
	}
	for (int i = ymin; i <= ymax; i++) {
		for (int j = xmin; j <= xmax; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	

	return 0;
}