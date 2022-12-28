#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    while(true){
        if(num == 1){
            return answer;
        }
        if(answer == 800)
            return -1;
        
        if (num % 2 == 0){
            num = num/2;
        }
        else if (num % 2 == 1){
            num = num * 3 + 1;
        }
        answer++;
    }
}