#include<iostream>
// #include<vector>
// #include<map>
// #include<algorithm>

using namespace std;

int main(){
    string dish;
    cin >> dish;

    char temp = dish[0];
    int answer = 10;

    for(int i=1; i<dish.length(); i++){
        if(temp == dish[i])
            answer += 5;
        
        else{
            answer += 10;
            temp = dish[i];
        }
    }

    cout << answer;
}