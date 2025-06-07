#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

// Check if the current character is an operator
bool isopeartor(char c){
    return c=='*'||c=='/'||c=='-'||c=='+'||c=='^';
}

int main()
{
    string postfix;
    stack<int> stk;
    cout << "Enter the postfix expression: ";
    cin >> postfix;
    int evaluated_result;

    // Loop for all the characters in the string
    for(int i = 0; i < postfix.length(); i++)
    {   
        // Check if the current character is a number
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            int num = postfix[i] - '0'; // Convert char to int
            stk.push(num);
        }
        // Check if the current character is operator
        else if(isopeartor(postfix[i])) {
            if (stk.size() < 2) {
                cout << "Invalid postfix expression!" << endl;
                return 1;
            }
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            char opp = postfix[i];
            int result = 0;
            switch(opp) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero error!" << endl;
                        return 1;
                    }
                    result = a / b;
                    break;
                case '^':
                    result = pow(a, b);
                    break;
            }
            stk.push(result);
        }
        // Ignore any other characters (optional: you can add error handling)
    }
    if (stk.size() != 1) {
        cout << "Invalid postfix expression!" << endl;
        return 1;
    }
    evaluated_result = stk.top();
    cout << "The evaluated result is: " << evaluated_result << endl;
    return 0;
}