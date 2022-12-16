#include<iostream>

using namespace std;

int main(){
    int time;
    cin >> time;

    int fiveM = time/300;
    time -= fiveM * 300;

    int Minu = time/60;
    time -= Minu * 60;

    int sec = time/10;
    time -= sec * 10;

    if(time != 0)
        cout << "-1";
    else
        cout << fiveM << " " << Minu << " " << sec;
}