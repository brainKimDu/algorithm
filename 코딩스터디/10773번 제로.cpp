#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	stack<int> sta;
	int tmp;
	int t; cin >> t;
	while (t--) {
		cin >> tmp;
		if (tmp == 0)
			sta.pop();
		else
			sta.push(tmp);
	}

	int sum = 0;
	while (!sta.empty()) {
		sum += sta.top();
		sta.pop();
	}
	cout << sum;
}