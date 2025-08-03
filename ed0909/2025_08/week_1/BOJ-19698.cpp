#include <iostream>

using namespace std;

int main() {

	int n, w, h, l;
	cin >> n >> w >> h >> l;
	int num = (w / l) * (h / l);
	if (num > n)cout << n;
	else cout << num;

	return 0;
}