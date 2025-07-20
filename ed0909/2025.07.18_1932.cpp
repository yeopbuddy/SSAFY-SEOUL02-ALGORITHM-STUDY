#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<int>>tree(n);
	vector<vector<int>>sum(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int temp;
			cin >> temp;
			tree[i].push_back(temp);
		}
		if (i == 0)sum[i][0] = tree[i][0];
		if (i > 0) {
			for (int j = 0; j < tree[i - 1].size(); j++) {
				for (int k = j; k <= j + 1; k++) {
					if (sum[i][k] != 0 && sum[i - 1][j] + tree[i][k] > sum[i][k])sum[i][k] = sum[i - 1][j] + tree[i][k];
					else if (sum[i][k] == 0)sum[i][k] = sum[i - 1][j] + tree[i][k];
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (sum[n - 1][i] > max)max = sum[n - 1][i];
	}
	cout << max;

	return 0;
}