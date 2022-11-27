#include<iostream>
#include<vector>

using namespace std;


int solution(vector<vector<int>> board) {
    vector<vector<int>> tempV = board;
    int answer = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {    
            if (board[i][j] == 1 ) {
                tempV[i][j] = 1;
            }

            else {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    if (board[i - 1][j - 1] == 1) 
                        tempV[i][j] = 1;
                }

                if (i - 1 >= 0) {
                    if (board[i - 1][j] == 1)
                        tempV[i][j] = 1;
                }


                if (i - 1 >= 0 && j + 1 < board[0].size()) {
                    if (board[i - 1][j + 1] == 1)
                        tempV[i][j] = 1;
                } 

                if (j - 1 >= 0) {
                    if (board[i][j - 1] == 1) {
                        tempV[i][j] = 1;
                    }
                }


                if (j + 1 < board[0].size()) {
                    if (board[i][j + 1] == 1)
                        tempV[i][j] = 1;
                }

                if (i + 1 < board.size() && j - 1 >= 0) {
                    if (board[i + 1][j - 1] == 1)
                        tempV[i][j] = 1;
                }

   
                if (i + 1 < board.size()) {
                    if (board[i + 1][j] == 1)
                        tempV[i][j] = 1;
                }


                if (i + 1 < board.size() && j + 1 < board[0].size()) {
                    if (board[i + 1][j + 1] == 1)
                        tempV[i][j] = 1;
                }
            }
        }
    }
    

    for (int i = 0; i < tempV.size(); i++) {
        for (int j = 0; j < tempV[0].size(); j++) {
            if (tempV[i][j] == 0) {
                answer += 1;
            }
            //cout << tempV[i][j] << " ";
        }
        //cout << endl;
    }

    return answer;
}


int main() {
    vector<vector<int>> v = { {0, 0, 0, 0, 0} ,{0, 0, 0, 0, 0},{0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0} };
    //vector<vector<int>> v = { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0} };
    //vector<vector<int>> v = { {1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1} };
    cout << solution(v);
}