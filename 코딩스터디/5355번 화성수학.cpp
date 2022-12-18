#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 속도를 높히려면 사용하는 구문이라고 함
	cout << fixed; cout.precision(2);
	// 소수점 2째자리까지 출력한다 
	int t; cin >> t;
	// 게임을 몇판 돌릴 건지

	while (t--) {
		// t--해서 0까지 돌리는 방법
		double k; cin >> k;
		// 숫자를 받고 나서
		string a; getline(cin, a);
		// 나머지는 문자열로 받는다.


		for (auto i : a) {
			// 문자열의 길이만큼 i의 값으로 받아오는 느낌
			if (i == '@') k *= 3;
			else if (i == '%') k += 5;
			else if (i == '#') k -= 7;
		} cout << k << "\n";
	}
	return 0;
}