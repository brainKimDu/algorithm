#include<iostream>

using namespace std;

int main() {
	int hour;
	int minute;

	int cooking;

	cin >> hour >> minute;
	cin >> cooking;

	minute += cooking;

	while (minute >= 60) {
		hour += 1;
		minute -= 60;
		if (hour == 24)
			hour = 0;
	}

	cout << hour << " " << minute;


}