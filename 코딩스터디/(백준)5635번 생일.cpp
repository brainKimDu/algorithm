#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	int player;
	cin >> player;

	map<int, string> m;
	vector<int> v;

	string name;
	string day;
	string month;
	string year;

	for (int i = 0; i < player; i++) {
		cin >> name >> day >> month >> year;

		if (day.length() == 1)
			day = '0' + day;
		if (month.length() == 1)
			month = '0' + month;

		v.push_back(stoi(year + month + day));
		m.insert({ stoi(year + month + day), name });
	}

	sort(v.begin(), v.end());

	cout << m[v[v.size() - 1]]  << endl << m[v[0]];
}