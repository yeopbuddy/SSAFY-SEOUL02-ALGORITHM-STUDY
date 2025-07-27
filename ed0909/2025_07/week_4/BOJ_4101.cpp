// 플젝때문에 스트릭만 유지
#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)break;
        else {
            if (n > m)cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }

    return 0;
}