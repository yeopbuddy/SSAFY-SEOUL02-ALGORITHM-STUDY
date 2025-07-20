// 문제 제목 : 같이 눈사람 만들래?
// 문제 난이도 : 골드 3
// 문제 요약 : 주어진 요소들 중 2개의 요소를 2쌍 선택해서, 각각의 합의 차이가 최솟값 찾기

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool Duplicate(int a, int b, int c, int d) {
	if (a != c && a != d && b != c && b != d) {
		return true;
	}
	return false;
}

int main() {
	
	int N;
	cin >> N;
	vector<int> Snow(N);

	for (int i = 0; i < N; i++) {
		cin >> Snow[i];
	}

	sort(Snow.begin(), Snow.end());

	vector<tuple<int, int, int>> SnowBall;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			SnowBall.push_back({ Snow[i] + Snow[j] , i, j});
		}
	}

	sort(SnowBall.begin(), SnowBall.end());
	
	int Ans = Snow[2] + Snow[3] - Snow[1] - Snow[0];

	for (int i = 1; i < SnowBall.size(); i++) {
		int CVal = get<0>(SnowBall[i]) - get<0>(SnowBall[i - 1]);
		if (CVal < Ans && Duplicate(get<1>(SnowBall[i]), get<2>(SnowBall[i]), get<1>(SnowBall[i - 1]), get<2>(SnowBall[i - 1]))) {
			Ans = CVal;
		}
	}
	cout << Ans;
}