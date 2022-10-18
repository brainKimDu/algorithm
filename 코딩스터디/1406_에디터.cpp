
#include<iostream>
#include<string>
#include<list>

using namespace std;

int main() {
	list<char> L;
	string insertSTR;

	cin >> insertSTR;
	if (insertSTR.length() > 100000)
		return 0;
	for (int i = 0; i < insertSTR.length(); i++) {
		L.push_back(insertSTR[i]);
	}

	list<char>::iterator iter;
	iter = L.end();
	

	int sizeOrder;
	char sel;

	cin >> sizeOrder;
	if (sizeOrder > 500000 && sizeOrder < 1)
		return 0;


	cin.ignore();

	for (int i = 0; i < sizeOrder; i++) {
		cin >> sel;
		switch (sel) {
		case 'L':
			if (iter != L.begin())
				iter--;
			break;
		case 'D':
			if (iter != L.end())
				iter++;
			break;
		case 'B':
			if (iter != L.begin()) {
				iter--;
				iter = L.erase(iter);
			}
			break;
		case 'P':
			cin >> sel;
			if (sel >= 'a' && sel <= 'z') {
				L.insert(iter, sel);
			}
			break;
		}
	}
	
	for (iter = L.begin(); iter != L.end(); iter++) {
		cout << *iter;
	}


}