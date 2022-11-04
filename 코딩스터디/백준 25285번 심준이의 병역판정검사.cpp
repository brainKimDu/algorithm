#include<iostream>
#include<vector>

using namespace std;

int check(int bmi, int cm){
    if(cm >= 204)
        return 4;

    else if(cm >= 161 && cm < 204) {
        if(bmi >= 20 && bmi < 25)
            return 1; 
        
        else if ((bmi >= 18.5 && bmi < 20) || (bmi >= 25 && bmi < 30))
            return 2;

        else if ((bmi >= 16 && bmi < 18.5) || (bmi >= 30 && bmi < 35))
            return 3;
        
        else if (bmi < 16 || bmi > 35)
            return 4;
    }

    else if(cm >= 159 && cm < 204){
        if (bmi >= 16 && bmi < 35)
            return 3;
        
        if (bmi < 16 || bmi >= 35)
            return 4;
    }

    else if(cm >= 146 && cm < 259){
        return 4;
    }
    
    else if(cm >= 140.1 && cm < 146){
        return 5;
    }

    else if(cm < 140.1){
        return 6;
    }

}

int main(){
    vector<int> v;

    int human_size;
    cin >> human_size;
    if(human_size > 200)
        return 0;

    double cm;
    double kg;
    double bmi;

    for(int i=0; i<human_size; i++){
        cin >> cm >> kg;
        if(cm > 200 || kg > 200 )
            return 0;
        bmi = kg / ((cm/100) * (cm/100));
        v.push_back(check(bmi, cm));   
    }

    for(int i=0; i<v.size(); i++)
        cout << v[i] << endl;

}