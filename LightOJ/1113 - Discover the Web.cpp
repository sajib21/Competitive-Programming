#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        string tk, ad;
        stack<string>one, two;

        one.push("http://www.lightoj.com/");

        printf("Case %d:\n", t);

        while(cin >> tk && tk != "QUIT") {
            if(tk == "VISIT") {
                cin >> ad;
                one.push(ad);
                cout << ad << endl;
                while(!two.empty()) two.pop();
            }
            else if(tk == "BACK") {
                string tp = one.top();
                if(tp != "http://www.lightoj.com/") {
                    two.push(tp);
                    one.pop();
                    cout << one.top() << endl;
                }
                else {
                    cout << "Ignored" << endl;
                }
            }
            else {
                string tp;
                if(!two.empty()) {
                    one.push( two.top() );
                    two.pop();
                    cout << one.top() << endl;
                }
                else {
                    cout << "Ignored" << endl;
                }
            }
        }
    }
    return 0;
}
