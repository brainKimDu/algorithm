#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	vector<int> v;
	int t = 8;
	int temp;

	while (t--) {
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> tmp = v;
	sort(tmp.begin(), tmp.end());
	reverse(tmp.begin(), tmp.end());
	cout << tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] << endl;

	vector<int> answer;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (tmp[i] == v[j]) {
				answer.push_back(j+1);
			}
		}
	}

	sort(answer.begin(), answer.end());
	for (auto i : answer)
		cout << i << " ";

}