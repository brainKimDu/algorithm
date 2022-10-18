#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, string> m;
    int count = 0;
    
    string temp = "";
    string answer = "";

    m.insert({"zero", "0"});
    m.insert({"one", "1"});
    m.insert({"two", "2"});
    m.insert({"three", "3"});
    m.insert({"four", "4"});
    m.insert({"five", "5"});
    m.insert({"six", "6"});
    m.insert({"seven", "7"}); 
    m.insert({"eight", "8"});
    m.insert({"nine", "9"});


    for(int i=0; i<s.length(); i++ ){
        if(s[i] >= 97 && s[i] <=122){
            temp += s[i];
            if(m.find(temp) != m.end() ){
                answer += m.at(temp);
                temp = "";
            }
        }

        else{
            answer += s[i];
        }
    }

    return stoi(answer);
}

int main(){
    string s;
    cin >> s;

    cout <<  solution(s);
}