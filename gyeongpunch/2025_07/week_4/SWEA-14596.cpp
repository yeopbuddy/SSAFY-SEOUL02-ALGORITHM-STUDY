#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 20;
const int MAX_HASH = 9999;

int n;
int initMap[MAX_N + 2][MAX_N + 2];
int modifiedMap[MAX_N + 2][MAX_N + 2];

struct Candidate {
	int r;
	int c;
	bool isHorizontal;
	bool isReverse;
};

vector<Candidate> candidate[MAX_HASH + 1];

void init(int N, int mMap[20][20])
{
	n = N;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			modifiedMap[i + 1][j + 1] = initMap[i + 1][j + 1] = mMap[i][j];
		}
	}

	for (int i = 0; i <= MAX_HASH; i++) {
		candidate[i].clear();
	}

	for (int length = 2; length <= 5; length++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + length - 1 <= n; j++) {

				int hash = 0;
				for (int k = 0; k + 1 < length; k++) {
					hash = hash * 10 + (initMap[i][j + k + 1] - initMap[i][j + k] + 5);
				}
				candidate[hash].push_back({ i, j, true, false });


				int reverseHash = 0;
				for (int k = length - 1; k - 1 >= 0; k--) {
					reverseHash = reverseHash * 10 + (initMap[i][j + k - 1] - initMap[i][j + k] + 5);
				}
				if (reverseHash != hash) {
					candidate[reverseHash].push_back({ i, j, true, true });
				}
			}
		}

		for (int i = 1; i + length - 1 <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int hash = 0;
				for (int k = 0; k + 1 < length; k++) {
					hash = hash * 10 + (initMap[i + k + 1][j] - initMap[i + k][j] + 5);
				}
				candidate[hash].push_back({ i, j, false, false });

				int reverseHash = 0;
				for (int k = length - 1; k - 1 >= 0; k--) {
					reverseHash = reverseHash * 10 + (initMap[i + k - 1][j] - initMap[i + k][j] + 5);
				}
				if (reverseHash != hash) {
					candidate[reverseHash].push_back({ i, j, false, true });
				}
			}
		}
	}
}

int numberOfCandidate(int M, int mStructure[5])
{
	if (M == 1) {
		return n * n;
	}

	int hash = 0;
	for (int i = 0; i + 1 < M; i++) {
		hash = hash * 10 + (mStructure[i] - mStructure[i + 1] + 5);
	}
	return candidate[hash].size();
}

bool check[MAX_N + 2][MAX_N + 2];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Point {
	int x, y;
};

int unsubmergedArea(int mMap[MAX_N + 2][MAX_N + 2], int mSeaLevel) {
	queue<Point> q;

	for (int i = 0; i <= n + 1; i++){
		for (int j = 0; j <= n + 1; j++){
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1){
				q.push({ i, j });
				check[i][j] = true;
			}
			else
				check[i][j] = false;
		}
	}

	int nx, ny;
	while (!q.empty()) {
		Point now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (nx < 0 || nx > n+1 || ny < 0 || ny > n+1) continue;
			if (check[nx][ny]) continue;
			if (mMap[nx][ny] >= mSeaLevel) continue;

			q.push({ nx, ny });
			check[nx][ny] = 1;
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!check[i][j]) {
				ret++;
			}
		}
	}
	return ret;
}

int maxArea(int M, int mStructure[5], int mSeaLevel)
{
	int ret = -1;

	if (M == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				modifiedMap[i][j] = initMap[i][j] + mStructure[0];
				ret = max(ret, unsubmergedArea(modifiedMap, mSeaLevel));
				modifiedMap[i][j] = initMap[i][j];
			}
		}
		return ret;
	}

	int hash = 0;
	for (int i = 0; i + 1 < M; i++) {
		hash = hash * 10 + (mStructure[i] - mStructure[i + 1] + 5);
	}

	for (const Candidate &wall : candidate[hash]) {
		if (wall.isHorizontal) {
			int height = mStructure[0] + (wall.isReverse ? initMap[wall.r][wall.c + M - 1] : initMap[wall.r][wall.c]);
			for (int i = 0; i < M; i++) {
				modifiedMap[wall.r][wall.c + i] = height;
			}
			ret = max(ret, unsubmergedArea(modifiedMap, mSeaLevel));
			for (int i = 0; i < M; i++) {
				modifiedMap[wall.r][wall.c + i] = initMap[wall.r][wall.c + i];
			}
		}
		else {
			int height = mStructure[0] + (wall.isReverse ? initMap[wall.r + M - 1][wall.c] : initMap[wall.r][wall.c]);
			for (int i = 0; i < M; i++) {
				modifiedMap[wall.r + i][wall.c] = height;
			}
			ret = max(ret, unsubmergedArea(modifiedMap, mSeaLevel));
			for (int i = 0; i < M; i++) {
				modifiedMap[wall.r + i][wall.c] = initMap[wall.r + i][wall.c];
			}
		}
	}
	

	return ret;
}