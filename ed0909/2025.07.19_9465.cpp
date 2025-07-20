#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		vector<vector<int>>book(2, vector<int>(n));
		vector<vector<int>>sum(3, vector<int>(n,-1));
		for (int i = 0; i < 2 * n; i++) {
			cin >> book[i / n][i % n];
		}
		sum[0][0] = book[0][0];
		sum[1][0] = book[1][0];
		sum[2][0] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 2; k++) {
					if (k == j)continue;
					if (sum[k][i] == -1) {
						sum[k][i] = sum[j][i - 1] + book[k][i];
					}
					else if (sum[k][i] != -1 && sum[k][i] < sum[j][i - 1] + book[k][i])sum[k][i] = sum[j][i - 1] + book[k][i];
				}
			}
			int max = 0;
			for (int j = 0; j < 3; j++) {
				if (max < sum[j][i - 1])max = sum[j][i - 1];
			}
			sum[2][i] = max;
		}
		int result = 0;
		for (int i = 0; i < 3; i++) {
			if (result < sum[i][n - 1])
				result = sum[i][n - 1];
		}

		cout << result << "\n";
	}

	return 0;
}