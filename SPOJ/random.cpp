#include<bits/stdc++.h>

using namespace std;

int main() {

    freopen("in.txt", "w", stdout);

    int T = 10;
    cout << T << endl ;

    for(int t=1; t<=T; t++) {

        cout << endl;

        int n = 6;
        cout << n ;
        for(int i=0; i<n; i++) cout << ' ' << (rand() % 20) * (rand()%10 - 5) ;
        cout << endl;
        int q = 10;
        cout << q << endl;
        while(q--) {
            int x1,y1,x2,y2;
            x1 = rand() % n + 1;
            do{
                y1 = rand() % n + 1;
            }while(y1 < x1);
            do{
                x2 = rand() % n + 1;
            }while(x2 < x1);
            do{
                y2 = rand() % n + 1;
            }while(y2 < x2 || y2 < y1);

            cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        }
    }
}
