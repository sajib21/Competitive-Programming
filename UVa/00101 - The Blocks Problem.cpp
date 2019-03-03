#include <bits/stdc++.h>

using namespace std;

void stackPrint(stack<int> stk) {

    if(stk.empty()) return;
    int t = stk.top();
    stk.pop();
    stackPrint(stk);
    printf(" %d", t);
}



int main() {

    int n;

    while(cin >> n) {

        stack<int>stk[30];
        int address[30];
        for(int i=0; i<n; i++) {
            address[i] = i;
            stk[i].push(i);
        }
        string s1, s2;
        int a,b;
        cin >> s1;

        while(s1.compare("quit")) {

            cin >> a;
            cin >> s2;
            cin >> b;

            int adA = address[a] , adB = address[b];

            if(adA == adB || a == b) {
                cin >> s1;
                continue;
            }

            if(!s1.compare("move")) {

                while(stk[adA].top() != a) {
                    int t = stk[adA].top();
                    stk[adA].pop();
                    address[t] = t;
                    stk[t].push(t);
                }
            }

            if(!s2.compare("onto")) {

                while(stk[adB].top() != b) {
                    int t = stk[adB].top();
                    stk[adB].pop();
                    address[t] = t;
                    stk[t].push(t);
                }
            }

            int t; stack<int>temp;
            do {
                t = stk[adA].top();
                stk[adA].pop();

                //stk[adB].push(t);
                temp.push(t);
                //address[t] = adB;
                //cout << "debug" << endl;
            } while(t != a);

            while(!temp.empty()) {
                address[ temp.top() ] = adB;
                stk[adB].push( temp.top() );
                temp.pop();
            }

            //cout << "do theka bair hoise" << endl;
            cin >> s1;

        }

        int adA = address[a] , adB = address[b];


        for(int i=0; i<n; i++) {
            printf("%d:", i);
            stackPrint(stk[i]);
            printf("\n");
        }
    }

    return 0;

}
