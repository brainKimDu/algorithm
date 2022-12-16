#include<iostream>

using namespace std;

int main(){
    string sco;
    cin >> sco;

    if(sco == "A+")
        cout << "4.3";
    else if (sco == "A0"){
        cout << "4.0";
    }
    else if (sco == "A0"){
        cout << "4.0";
    }
    else if (sco == "A-"){
        cout << "3.7";
    }
    else if (sco == "B+"){
        cout << "3.3";
    }
    else if (sco == "B0"){
        cout << "3.0";
    }
    else if (sco == "B-"){
        cout << "2.7";
    }
    else if (sco == "C+"){
        cout << "2.3";
    }
    else if (sco == "C0"){
        cout << "2.0";
    }
    else if (sco == "C-"){
        cout << "1.7";
    }
    else if (sco == "D+"){
        cout << "1.3";
    }
    else if (sco == "D0"){
        cout << "1.0";
    }
    else if (sco == "D-"){
        cout << "0.7";
    }
    else if (sco == "F"){
        cout << "0.0";
    }

}