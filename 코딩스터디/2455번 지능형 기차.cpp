#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int MAX = 0;
	int people = 0;
	int in;
	int out;

	int t = 4;
	while (t--) {
		cin >> out >> in;
		people -= out;
		people += in;
		if (people > MAX)
			MAX = people;
	}

	cout << MAX;
}