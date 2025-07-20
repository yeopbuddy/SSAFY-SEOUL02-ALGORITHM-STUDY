#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	string sen1, sen2;
	cin >> sen1 >> sen2;
	vector<vector<int>>dp(sen1.length() + 1, (vector<int>(sen2.length() + 1, 0)));
	for (int i = 1; i <= sen1.length(); i++) {
		for (int j = 1; j <= sen2.length(); j++) {
			if (sen1[i - 1] == sen2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[sen1.length()][sen2.length()];

	return 0;
}