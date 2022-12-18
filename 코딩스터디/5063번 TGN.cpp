#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> v;
	int temp;

	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 3; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		
		if ((v[1] - v[2]) > v[0]) 
			cout << "advertise";
		else if ((v[1] - v[2]) < v[0])
			cout << "do not advertise";
		else if ((v[1] - v[2]) == v[0])
			cout << "does not matter";

		v.clear();

	}

}