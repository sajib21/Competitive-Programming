#include<bits/stdc++.h>

using namespace std;

int priority(char a) {
    int nnode=100;

    switch (a) {
        case '(' :
            nnode = 1;
            break;
        case '+' :
            nnode = 2;
            break;
        case '.' :
            nnode = 3;
            break;
        case '*' :
            nnode = 4;
            break;
    }
    return nnode;
}
string formatRegEx(string regex) {
    string res = "";
    vector<char> allOperators{'+', '*'};
    vector<char> binaryOperators{'+'};

    for (int i = 0; i < regex.size(); i++) {
        char c1 = regex.at(i);
        if (i + 1 < regex.size()) {
            char c2 = regex.at(i + 1);
            res += c1;
            if (c1!='(' && c2 != ')' && find(begin(allOperators),end(allOperators),c2)==end(allOperators) && find(begin(binaryOperators),end(binaryOperators),c1)==end(binaryOperators)) {
                res += '.';
            }
        }
    }
    res += regex.at(regex.length() - 1);
    return res;
}
string infixToPostfix(string regex) {
    string postfix = "";

    stack<char> st;

    string formattedRegEx = formatRegEx(regex);
    for (int i=0 ; i< formattedRegEx.length() ; i++) {
        char c = formattedRegEx.at(i);
        if(c== '(') {
            st.push(c);
            continue;

        } else if(c==')') {
            while (st.top() !='(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
            continue;
        } else {
            while (!st.empty()) {
                char peekedChar = st.top();
                int pcp = priority(peekedChar);
                int ccp= priority(c);

                if (pcp >= ccp) {
                    postfix += st.top();
                    st.pop();
                } else
                    break;
            }
            st.push(c);
            continue;
        }

    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string str;
    while(cin >> str) cout << infixToPostfix(str) << endl;
}
