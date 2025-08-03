#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> num(n + 1, 0);
	vector<int> sum(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		sum[i] = sum[i - 1] + num[i];
	}

	int start = 0;
	int len = 21e7;

	for (int end = 1; end <= n; end++) {
		while (sum[end] - sum[start] >= m) {
			if (len > end - start) len = end - start;
			start++;
		}
	}

	if (len == 21e7) cout << "0";
	else cout << len;

	return 0;
}
