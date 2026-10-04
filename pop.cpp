#include <iostream>
using namespace std;

int main() {
    int stack[5];
    int top = -1;

    // Push elements
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    cout << "Top element: " << stack[top] << endl;

    // Pop
    if (top == -1) {
        cout << "Stack is empty";
    } else {
        cout << "Popped element: " << stack[top] << endl;
        top--;
    }

    cout << "New top: " << stack[top] << endl;

    return 0;
}