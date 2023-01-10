#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	if (A > B)
		cout << "A";
	else if (A == B)
		cout << "same";
	else if (A < B)
		cout << "B";
}