#include<iostream>
#include<list>

using namespace std;

int main() {
	list<int> L;
	
	int size;

	cin >> size;

	int insert_int;

	list<int>::iterator iter;


	cin >> insert_int;
    // 맨앞자리 친구는 무조건 맨뒤에 붙어야 해서 예시에서도 0을 줄 수 밖에 없는 상황
    // 그래서 그냥 입력하나 받고 버리자
	L.push_back(1);
    // 맨뒤에 1을 삽입

	// 2부터 들어가야하니 2부터 시작하고 size+1까지
	for (int i = 2; i < size+1; i++) {
		cin >> insert_int;
        // 입력받고
		iter = L.end();
        // iterator를 맨 끝을 바라보게 하자.
		for (int j = 0; j < insert_int; j++) {
			iter--;
            // 입력된 수만큼 뒤로 이동해서
		}
		L.insert(iter, i);
        // 삽입해라.
	}

	for (iter = L.begin(); iter != L.end(); iter++) {
		cout << *iter << " ";
	}
    // 다 출력해주세요.
}