#include<iostream>
#include<algorithm>  // sort 하기 위해 선언
#include<vector>

using namespace std;

int main() {
	vector<int> v;
    
    
	int sell;
	cin >> sell;
    // 팔린 티켓들의 총 개수


	int insert_seat;
   	// 어떤 자리가 팔렸는가
    
	for (int i = 0; i < sell; i++) {
		cin >> insert_seat;
		v.push_back(insert_seat);
        // 팔린 자리에 대한 정보를 저장
	}

	sort(v.begin(), v.end());
    // 팔린 자리에 대한 정보를 sort 한다.

	int low_seat = 1;
    // 1의 값을 가지는 low_seat
    
    // for 문을 돌면서 가장 낮은 수의 자리가 나오면 그 값을 리턴한다.
	for (int i = 0; i < sell; i++) {
		if (low_seat == v[i])
			low_seat++;
		else
			break;
	}

	// 출력해라. 
	cout << low_seat;

}