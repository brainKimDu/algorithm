#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {

	string before;
	string after;
	char yeon;

	cin >> before;
	cin >> yeon;
	cin >> after;

	if (yeon == '*') {
		cout << 1;
		for (int i = 0; i < before.length() + after.length() - 2; i++) {
			cout << 0;
		}
	}

	else if (yeon == '+') {
		int len;

		if (before.length() > after.length())
			len = before.length();
		else
			len = after.length();

		for (int i = len; i > 0; i--) {
			if (i == after.length() || i == before.length())
				if (after.length() == before.length())
					cout << 2;
				else
					cout << 1;
			else
				cout << 0;
		}
	}
}