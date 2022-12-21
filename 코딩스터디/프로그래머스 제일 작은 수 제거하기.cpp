#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> answer;
    if(v.size() != 1){
        int min_index = min_element(v.begin(), v.end())-v.begin();
        v.erase(v.begin() + min_index);
        answer = v;
        return answer;
    }
    else{
        answer.push_back(-1);
        return answer;
    }
}