#include<bits/stdc++.h>

using namespace std;

int main() {

    //FILE *fp = fopen("out.txt", "w");

    int t;
    cin >> t;
    getchar();
    while(t--) {

        string s;
        //cin >> s;
        getline(cin, s);

        //cout << s;
        //getchar();

        bool flag = true;

        stack<char>stk;

        int sz = s.size() ;
        for(int i=0; i<sz; i++) {
            if(stk.empty()) {
                if(s[i] == '(' || s[i] == '[') {
                    stk.push(s[i]);
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if(s[i] == '(' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                char samne = stk.top();
                if(samne == '(' && s[i] == ')') {
                    stk.pop();
                }
                else if(samne == '[' && s[i] == ']') {
                    stk.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        if(!flag || !stk.empty()) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }



    }

    //fclose(fp);

    return 0;

}
