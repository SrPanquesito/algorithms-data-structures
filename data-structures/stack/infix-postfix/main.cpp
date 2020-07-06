// Convert an aritmetic expression written on infix to postfix for computer evaluation.
// Using ASCII Table ;)

// -------- ONLY 0 - 9 numbers and + - * / basic operators. -----------
#include <iostream>
#include <stack>
#define MAX_SIZE 1001
using namespace std;

// True or false if character is operator or sparator
int isOperator(char * ch) {
    if (
        // () [] {}
        *ch == 40 || *ch == 41 ||
        *ch == 91 || *ch == 93 ||
        *ch == 123 || *ch == 125 ||
        // * + - / 
        *ch == 42 || *ch == 43 || *ch == 45 || *ch == 47 
        ) {
        return 1;
    } else {
        return 0;
    }
}
int isOpeningSeparator(char ch) {
    if (
        ch == 40 ||
        ch == 91 ||
        ch == 123
        ) {
        return 1;
    } else {
        return 0;
    }
}

// Which operators have higher priority
int hasHigherOrEqualPrecedence(char stackCh, char ch) {
    // Equal higher precedence * /
    if ((stackCh == 42 || stackCh == 47) && (ch == 42 || ch == 47 || ch == 43 || ch == 45)) {
        return 1;
    }
    // Equal precedence + -
    else if ((stackCh == 43 || stackCh == 45) && (ch == 43 || ch == 45)) {
        return 1;
    }
    else {
        return 0;
    }
}

// Are () [] {} the correct matches?
int matchingSeparators(char stackCh, char ch) {
    // Almost near each other in ASCII table
    if (stackCh+1 == 41 || stackCh+2 == 93 || stackCh+2 == 125) {
        return 1;
    }
    else {
        return 0;
    }
}

const char * infixToPostfix(char str[], stack<char> * s) {
    int i = 0, c = 0, error = 0;
    static char postfix[MAX_SIZE];

    while (str[i] != '\0' && str[i] != '\n' && str[i] != 0) {
        // If space or number (operand)
        if (str[i] == ' ' || (str[i] >= 48 && str[i] <= 57)) {
            // Right now only works for 0-9 numbers ......
            // Need to capture number until end of space
            if (str[i] != ' ') {
                postfix[c] = str[i];
                c++;
            }
        }
        // If separator or operator
        else if (isOperator(&str[i])) {
            // Closing separators
            if (str[i] == 41 || str[i] == 93 || str[i] == 125) {
                while(!s->empty() && !matchingSeparators(s->top(), str[i])) {
                    postfix[c] = s->top();
                    s->pop();
                    c++;
                }
                if (!s->empty() && matchingSeparators(s->top(), str[i])) {
                    s->pop();
                } else {
                    cout << "\nClosing tags don't match with their opening tags. Verify your input.\n";
                    error = 1;
                    break;
                }
            } else {
                while(!s->empty() && !isOpeningSeparator(s->top()) && hasHigherOrEqualPrecedence(s->top(), str[i])) {
                    postfix[c] = s->top();
                    s->pop();
                    c++;
                }
                s->push(str[i]);
            }
        }
        // Every other character is not valid so imma_head_out.meme :v
        else {
            cout << "\n---------------Character not valid------------------\n";
            printf("%d -----> %c", str[i], str[i]);
            cout << "\n--------------------------------------------------\n";
            error = 1;
            break;
        }
        i++;
    }

    if (error) {
        static char err[] = {'E', 'R', 'R', 'O', 'R', '\0'};
        return err;
    }
    else {
        while (!s->empty()) {
            postfix[c] = s->top();
            s->pop();
            c++;
        }
        postfix[c] = '\0';

        return postfix;
    }
}

int main() {
    system("cls");

    stack<char> s;
    char str[MAX_SIZE];
    cout << "Writte an aritmetic operation:\n\n";
    fgets(str, MAX_SIZE, stdin);

    printf("%s", infixToPostfix(str, &s));
    return 0;
}