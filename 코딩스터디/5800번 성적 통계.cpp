#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int temp;

	vector <string> ans;

	int t; cin >> t;
	while (t--) {
		vector<int> v;
		int a; cin >> a;
		for (int i = 0; i < a; i++) {
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		int MAX = 0;
		for (int i = 0; i < v.size()-1; i++) {
			if (v[i + 1] - v[i] > MAX) {
				MAX = v[i + 1] - v[i];
			}
		}
		ans.push_back("Max " + to_string(v[v.size() - 1]) + ", Min " + to_string(v[0]) + ", Largest gap " + to_string(MAX));
	}

	int c = 1;
	for (auto i : ans) {
		cout << "Class " << c << endl;
		cout << i << endl;
		c++;
	}

}