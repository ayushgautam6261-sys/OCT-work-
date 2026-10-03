#include <iostream>
using namespace std;

#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    }
    else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack." << endl;
    }
}

int main() {

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);

    // This will cause overflow
    push(110);

    return 0;
}