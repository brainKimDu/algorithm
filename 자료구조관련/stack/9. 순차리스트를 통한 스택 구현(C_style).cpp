#include<iostream>
using namespace std;
#define STACK_SIZE 100


int start_stack();
string stack[STACK_SIZE];
int top = start_stack();

//스택을 공백상태로 만들어준다.
int start_stack() {
    return 0;
}

// 스택이 공백상태인지 판단
bool empty_stack() {
    if (top > 0)
        return true;
    else
        return false;
}

// 스택이 가득차있는가?
bool full_stack() {
    if (top == 99) 
        return false;
    else
        return true;
}


// 순차리스트로 push를 구현한다
void push(string str) {
    if(full_stack() == true)
        stack[top++] = str;
    else {
        cout << "스텍이 꽉찼습니다.";
    }
}

// 순차리스트로 pop을 구현한다.
string pop() {
    string str;
    if (empty_stack() == true)
        return stack[(top--)-1];
    else {
        cout << "주의 : 빈 스텍입니다 " << endl;
        return "\0";
    }
}

// top 값을 출력해주세요.
string peek() {
    if (empty_stack() == false) 
        cout << "주의 : 빈 스텍입니다 " << endl;
    return stack[top-1];
}


// 스텍의 모든 요소들을 출력해주세요.
void print_stack_value() {
    cout << "STACK [";
    for (int i = 0; i < top; i++)
        cout << stack[i] << ",";
    cout << "] \n";
}



// 메인문
int main() {
    string insert_str;

    cout << "stack 입니다~" << endl;
  
    while (true) {
        print_stack_value();
        cout << "작업을 선택해주세요. >> 1. push    2.pop   3.peek 조회  4. 종료";
        int sel;
        cin >> sel;

        switch (sel) {
        case 1:
            cout << "push >> ";
            cin >> insert_str;
            push(insert_str);
            break;

        case 2:
            cout << "pop >> " << pop() << endl;
            break;

        case 3:
            cout << "peak = " << peek() << endl;
            break;

        case 4:
            cout << "종료합니다.";
            return 0;
            break;
        }
    }
}