#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	vector<string> ans;
	string name;
	int money;
	int many;
	cin >> many;
	


	for (int i = 0; i < many; i++) {
		map<int, string> m;
		vector<int> v;

		int player;
		cin >> player;

		for (int j = 0; j < player; j++) {
			cin >> money >> name;
			v.push_back(money);
			m.insert({money, name});
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		ans.push_back(m[v[0]]);
	}

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
