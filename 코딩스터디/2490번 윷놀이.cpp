#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int v[4];
	vector<char> a;

	int t = 3;
	while (t--) {
		char doge = 64;
		cin >> v[0] >> v[1] >> v[2] >> v[3];
		for (auto i : v) {
			if (i == 0) {
				doge += 1;
			}
		}
		if (doge == 64) {
			a.push_back('E');
		}
		else
			a.push_back(doge);
	}

	for (auto i : a)
		cout << i << endl;

}