#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int p;

int main() {

    while(cin >> p) {
        //cout <<  getWin(1) << endl;
        int n=1;
        bool win = true;
        while(p > 1) {

            win = !win;

            if(!win) {
                p = (p+8)/9;
                //win = !win;
            }
            else {
                p = (p+1)/2;
                //win = !win;
            }
            //if(p <= 1) break;
            //else win = !win;
        }

        if(!win) cout << "Stan wins." << endl;
        else cout << "Ollie wins." << endl;
    }

    return 0;
}
