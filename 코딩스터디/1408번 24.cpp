#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	vector<int> nowV;
	vector<int> startV;

	string now;
	string start;

	cin >> now;
	cin >> start;

	string Ntemp;
	string Stemp;

	for (int i = 0; i < now.length(); i++) {
		if (now[i] == ':') {
			nowV.push_back(stoi(Ntemp));
			Ntemp = "";
			startV.push_back(stoi(Stemp));
			Stemp = "";
		}
		else {
			Ntemp += now[i];
			Stemp += start[i];
		}
	}
	nowV.push_back(stoi(Ntemp));
	startV.push_back(stoi(Stemp));


	vector<int> ans;

	ans.push_back(startV[0] - nowV[0]);
	ans.push_back(startV[1] - nowV[1]);
	ans.push_back(startV[2] - nowV[2]);


	if (ans[2] < 0) {
		ans[2] +=  60;
		ans[1] -= 1;
	}

	if (ans[1] < 0) {
		ans[1] += 60;
		ans[0] -= 1;
	}

	if (ans[0] < 0) {
		ans[0] += 24;
	}

	vector<string> str;
	
	for (auto i : ans) {
		if (i < 10)
			str.push_back('0' + to_string(i));
		else
			str.push_back(to_string(i));
	}

	cout << str[0] << ':' << str[1] << ':' << str[2];

}