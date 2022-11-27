#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
	int answer = 0;
	int temp;

	while (chicken >= 10) {
		temp = chicken / 10;

		answer = answer + chicken / 10;

		chicken -= (chicken / 10) * 10;

		chicken += temp;

	}
	return answer;
}

int main() {
	int chicken;

	cin >> chicken;
	cout << solution(chicken);

}

