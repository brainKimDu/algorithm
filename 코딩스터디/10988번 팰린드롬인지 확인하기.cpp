#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	string str;
	cin >> str;

	string rts = "";

	for (auto i : str) {
		rts = i + rts;
	}

	if (str == rts)
		cout << 1;
	else
		cout << 0;
}