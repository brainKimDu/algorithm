// [1, 2, 3 ,4, 5]
// 예산을 입력했을때 최대 몇개의 부서까지 지원이 가능한가?
// 최대한 많은 부서한테 돈을 주는게 목표아닌가?
// https://twpower.github.io/90-combination-by-using-next_permutation
// 순열과 조합관련 알고리즘 연구도 필요 -> 순열과 조합 문제가 아니였다.

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(vector<int> d, int budget) {
    int answer=0; // count
    int sum = 0;

    sort(d.begin(), d.end());

    for(int i=0; i<d.size(); i++){
        sum += d[i];
        if(sum > budget){
                return answer;
                break;
        }
        answer++; 

    }

    return answer;
}
    


int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    //v.push_back(5);

    cout << solution(v, 10);

}