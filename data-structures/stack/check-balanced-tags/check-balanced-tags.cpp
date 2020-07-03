// Check balanced open close tags
// Tags being {} [] ()

#include <iostream>
#include <stack>
using namespace std;

bool balancedTags(char fileName[]) {
    FILE * fPtr;
    stack<char> s;
    fPtr = fopen(fileName, "r");

    while(!feof(fPtr)) {
        char c = fgetc(fPtr);
        cout << c;

        if (c == 40 || c == 91 || c == 123) {
            s.push(c);
        }
        else if (c == 41 || c == 93 || c == 125) {
            if (s.empty()) {
                fclose(fPtr);
                return false;
            }
            if (s.top() == 123 && c == 125) s.pop();
            else if (s.top() == 91 && c == 93) s.pop();
            else if (s.top() == 40 && c == 41) s.pop();
        }
    }
    fclose(fPtr);
    return s.empty() ? true : false;
}

int main () {
    cout << "\n\n";
    if (balancedTags("example.txt")) {
        cout << "All opening and closing tags are in place.";
    } else {
        cout << "ERROR: Opening and closing tags are not balanced.";
    }
    return 0;
}
