#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    string temp;
    int hap;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'Z') {
            if (s[i] != ' ') {
                temp += s[i];
            }
            else {
                answer += stoi(temp);
                hap = stoi(temp);
                temp = "";
            }
        }
        else {
            answer -= hap;
            hap = 0;
            i++;
        }
    }
    if (s[s.length() - 1] != 'Z')
        answer += stoi(temp);

    return answer;
}