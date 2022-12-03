#include<iostream>
#include<vector>
using namespace std;
#define STACK_SIZE 10000



int main() {
	vector<int> v;
	int stack[STACK_SIZE];
	int top = 0;

	string insert_str;
	int push_num;

	int size;

	cin >> size;

	for (int i = 0; i < size; i++) {
		cin >> insert_str;
		if (insert_str == "push") {
			cin >> push_num;
			stack[top++] = push_num;
		}

		else if (insert_str == "pop") {
			if (top != 0)
				v.push_back(stack[(top--)-1]);
			else
				v.push_back(-1);
		}

		else if (insert_str == "size") {
			v.push_back(top);
		}

		else if (insert_str == "empty") {
			if (top == 0)
				v.push_back(1);
			else
				v.push_back(0);
		}

		else if (insert_str == "top") {
			if (top != 0)
				v.push_back(stack[top-1]);
			else
				v.push_back(-1);
		}
	}

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}
