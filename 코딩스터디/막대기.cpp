#include<iostream>
​
using namespace std;
​
// 막대기를 일열로 새운다.
// 배열의 길이는 1000 000 개 -> 동적할당으로 해결
​
int main(){
    int size;
    int count = 1;
    int temp = 0;
​
    int num[1000000];
​
    cin >> size;
    if(size > 100000 || size <= 1)
        return 0;
    
    for(int i=0; i<size; i++){
        cin >> temp;
        if(temp <= 100000 && temp > 0)
            num[i] = temp;
        else
            return 0;
    }
​
    temp = num[size-1];
​
    // 뒤에서 바라볼때 자신보다 높을 값을 가지면 그 값을 가진다.
    for(int i = size-1; i>=0; i--){
       if(temp < num[i]){
        count++;
        temp = num[i];
       }
    }
    cout << count;
}