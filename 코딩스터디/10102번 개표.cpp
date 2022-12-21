#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int su; int A = 0; int B = 0;
	string sim;

	cin >> su;
	cin >> sim;

	for (int i = 0; i < su; i++) {
		if (sim[i] == 'A')
			A += 1;
		else if (sim[i] == 'B')
			B += 1;
	}

	if (A > B)
		cout << 'A';
	else if (A < B)
		cout << 'B';
	else if (A == B)
		cout << "Tie";
}