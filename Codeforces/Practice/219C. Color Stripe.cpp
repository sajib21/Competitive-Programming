#include<bits/stdc++.h>

using namespace std;

string str;

int main() {


    int n,k;
    cin >> n >> k;
    cin >> str;

    int moves = 0;

    if( k == 2 ) {
        for(int i=0; i<n; i++) {
            if(i%2 == 0) { if(str[i] != 'A') moves++; }
            else { if(str[i] != 'B') moves++; }
        }

        if(moves <= n - moves) {
            cout << moves << endl;
            for(int i=0; i<n; i++) {
                if(i%2 == 0) printf("A");
                else printf("B");
            }
        }
        else {
            cout << n - moves << endl;
            for(int i=0; i<n; i++) {
                if(i%2 == 0) printf("B");
                else printf("A");
            }
        }
        cout << endl;
        return 0;
    }

    else {
        for(int i=1; i<n; i++) {
            if(str[i-1] == str[i]) {
                for(char c='A', x=0; x<k; c++,x++) {
                    if(c != str[i] && c !=str[i+1]){
                        str[i] = c;
                        moves++;
                        break;
                    }
                }
            }
        }
        cout << moves << endl;
        cout << str << endl;
        return 0;
    }

}
