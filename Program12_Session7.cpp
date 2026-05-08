#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix to postfix (Shunting Yard - simple)
string toPostfix(string exp) {
    stack<char> st;
    string post = "";

    for (char c : exp) {

        if (isalnum(c)) {
            post += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                post += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c)) {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        post += st.top();
        st.pop();
    }

    return post;
}

// Generate TAC from postfix
void generateTAC(string postfix) {
    stack<string> st;
    int temp = 1;

    cout << "\nThree Address Code:\n";

    for (char c : postfix) {

        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();

            string t = "t" + to_string(temp++);

            cout << t << " = " << op1 << " " << c << " " << op2 << endl;

            st.push(t);
        }
    }
}

int main() {
    string expr;

    cout << "Enter expression (e.g., a=b+c*d): ";
    cin >> expr;

    // split RHS (ignore assignment)
    int i = 0;
    while (i < expr.size() && expr[i] != '=') i++;

    string rhs = expr.substr(i + 1);

    string postfix = toPostfix(rhs);

    generateTAC(postfix);

    return 0;
}
