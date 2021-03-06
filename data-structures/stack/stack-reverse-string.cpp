#include <iostream>
#include <stack>
using namespace std;

void Reverse(char * C, int len) {
    stack<char> stack;
    for(int i=0; i<len; i++) {
        stack.push(C[i]);
    }

    for(int i=0; i<len; i++) {
        C[i] = stack.top();
        stack.pop();
    }
}

int main() {
    char c[51];
    cout << "Enter a string: ";
    cin >> c;
    cout << "\n";
    Reverse(c, strlen(c));
    cout << "Output: " << c;
    return 0;
}