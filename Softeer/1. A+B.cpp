#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int A, B, t;
	vector<int> v;
	cin >> t; for (int i = 0; i < t; i++) {
		cin >> A >> B;
		cout << "Case #" << i+1 <<": " <<  A + B;
	}

}