#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string A, B;

	string enterHour, enterMin, exitHour, exitMin;

	int timeHour, timeMin;
	int time = 0;
	for (int i = 0; i < 5; i++) {
		cin >> A >> B;
		enterHour = to_string(A[0] - '0') + to_string(A[1] - '0');
		enterMin = to_string(A[3] - '0') + to_string(A[4] - '0');

		exitHour = to_string(B[0] - '0') + to_string(B[1] - '0');
		exitMin = to_string(B[3] - '0') + to_string(B[4] - '0');


		if (stoi(exitMin) >= stoi(enterMin)) {
			timeMin = abs(stoi(exitMin) - stoi(enterMin));
			timeHour = stoi(exitHour) - stoi(enterHour);
		}
		else {
			timeMin = 60 - abs(stoi(exitMin) - stoi(enterMin));
			timeHour = stoi(exitHour) - stoi(enterHour) - 1;
		}
		time += timeHour * 60 + timeMin;
	}

	cout << time;
}