#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// �ӵ��� �������� ����ϴ� �����̶�� ��
	cout << fixed; cout.precision(2);
	// �Ҽ��� 2°�ڸ����� ����Ѵ� 
	int t; cin >> t;
	// ������ ���� ���� ����

	while (t--) {
		// t--�ؼ� 0���� ������ ���
		double k; cin >> k;
		// ���ڸ� �ް� ����
		string a; getline(cin, a);
		// �������� ���ڿ��� �޴´�.


		for (auto i : a) {
			// ���ڿ��� ���̸�ŭ i�� ������ �޾ƿ��� ����
			if (i == '@') k *= 3;
			else if (i == '%') k += 5;
			else if (i == '#') k -= 7;
		} cout << k << "\n";
	}
	return 0;
}