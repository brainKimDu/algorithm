#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    int sun = 1;
    vector<int> temp = emergency;
    vector<int> comparison = emergency;

    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < temp.size(); j++) {
            if (temp[i] == emergency[j]) {
                comparison[j] = sun++;
                break;
            }
        }
    }
    return comparison;
}