// 내가 풀었던 코드 틀림.
#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left = 10, right = 12;

    int temp_left, temp_right;

    int left_distance, right_distance;

    int temp_value;

    bool center = false;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers.at(i) == 1 || numbers.at(i) == 4 || numbers.at(i) == 7) {
            answer += "L";
            left = numbers.at(i);
        }

        else if (numbers.at(i) == 3 || numbers.at(i) == 6 || numbers.at(i) == 9) {
            answer += "R";
            right = numbers.at(i);
        }

        else {
            // 0을 11로 보자.
            temp_value = numbers.at(i);
            if (temp_value == 0)
                temp_value = 11;

            if (left == 2 || left == 5 || left == 8 || left == 11) {
                temp_left = left;
                center = true;
            }
            else
                temp_left = left + 1;

            if (right == 2 || right == 5 || right == 8 || right == 11) {
                center = true;
                temp_right = right;
            }
            else
                temp_right = right - 1;
           

            left_distance = abs(temp_left - temp_value);
            right_distance = abs(temp_right - temp_value);

            

            if (left_distance > right_distance) {
                if (left_distance != 6 && right_distance != 6 && abs(left_distance - right_distance) == 3 && center == true) {
                    if (hand == "right") {
                        answer += "R";
                        right = temp_value;
                        center = false;
                    }

                    else if (hand == "left") {
                        answer += "L";
                        left = temp_value;
                        center = false;
                    }
                }
                
                else {
                    answer += "R";
                    right = temp_value;
                    center = false;
                }
             }

            else if (left_distance < right_distance) {
                if (left_distance != 6 && right_distance != 6 && abs(left_distance - right_distance) == 3 && center == true) {
                        if (hand == "right") {
                            answer += "R";
                            right = temp_value;
                            center = false;
                        }

                        else if (hand == "left") {
                            answer += "L";
                            left = temp_value;
                            center = false;
                        }
                 }
                

                else {
                    answer += "L";
                    left = temp_value;
                    center = false;
                }
            }

            else if (left_distance == right_distance) {
                if (hand == "right") {
                    answer += "R";
                    right = temp_value;
                    center = false;
                }

                else if (hand == "left") {
                    answer += "L";
                    left = temp_value;
                    center = false;
                }
            }
        }
    }
  

    return answer;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(0);
    cout << solution(v, "right");
}


// 정답
#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int left = 10, right = 12;

    int left_distance, right_distance;

    int temp_value;

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 1) {
            answer += "L";
            left = numbers[i];
        }

        else if (numbers[i] % 3 == 0 && numbers[i] != 0){
            answer += "R";
            right = numbers[i];
        }

        else {
            // 0을 11로 보자.
            temp_value = numbers[i];
            if (temp_value == 0)
                temp_value = 11;
           

            if (left % 3 == 1)
                left_distance = abs(temp_value - left - 1) / 3 + 1;
            else
                left_distance = abs(temp_value - left) / 3 ;


            if (right % 3 == 0)
                right_distance = abs(temp_value - right + 1) / 3 + 1;
            else
                right_distance = abs(temp_value - right) / 3;
     

            if (left_distance == right_distance) {
                if (hand[0] == 'l') {
                    answer += 'L';
                    left = temp_value;
                }

                else {
                    answer += 'R';
                    right = temp_value;
                }
            }

            else {
                if (left_distance < right_distance) {
                    answer += 'L';
                    left = temp_value;
                }

                else {
                    answer += 'R';
                    right = temp_value;
                }
            }
        }
        }
  

    return answer;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(0);

    //v.push_back(2);
    cout << solution(v, "right");
}