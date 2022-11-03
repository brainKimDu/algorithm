#include<iostream>
using namespace std;
#define STACK_SIZE 100

template <class T>
class stack {
    T stack_value[STACK_SIZE];
    int top;



public:
    stack() {
        top = 0;
    }

    bool empty_stack() {
        if (top > 0)
            return true;
        else
            return false;
    }


    bool full_stack() {
        if (top == 99)
            return false;
        else
            return true;
    }


    void push(T str) {
        if (full_stack() == true)
            stack_value[top++] = str;
        else {
            cout << "스텍이 꽉찼습니다.";
        }
    }

    T pop() {
        T str;
        if (empty_stack() == true)
            return stack_value[(top--) - 1];
        else {
            cout << "주의 : 빈 스텍입니다 " << endl;
            return 0;
        }
    }

    T peek() {
        if (empty_stack() == false)
            cout << "주의 : 빈 스텍입니다 " << endl;
        return stack_value[top - 1];
    }


    void print_stack_value() {
        cout << "STACK [";
        for (int i = 0; i < top; i++)
            cout << stack_value[i] << ",";
        cout << "] \n";
    }
};


int main() {
    stack<int> sta;
    int insert_str;
    cout << "stack 입니다~" << endl;
  
    while (true) {
        sta.print_stack_value();
        cout << "작업을 선택해주세요. >> 1. push    2.pop   3.peek 조회  4. 종료";
        int sel;
        cin >> sel;

        switch (sel) {
        case 1:
            cout << "push >> ";
            cin >> insert_str;
            sta.push(insert_str);
            break;

        case 2:
            cout << "pop >> " << sta.pop() << endl;
            break;

        case 3:
            cout << "peak = " << sta.peek() << endl;
            break;

        case 4:
            cout << "종료합니다.";
            return 0;
            break;
        }
    }
}