#include<iostream>
#include <string>
#include <vector>

using namespace std;


int solution(vector<int> numbers, int k) {
	int answer = 0;

	for (int i = 0; i < k-1; i++) {
		answer += 2;
		if (answer == numbers.size())
			answer = 0;
		else if (answer > numbers.size())
			answer = 1;
	}
	return numbers.at(answer);
}



int main() {

	vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	cout << solution(v, 2);
}