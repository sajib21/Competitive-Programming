#include<bits/stdc++.h>
#define LIM 10
using namespace std;

int main() {
    freopen("1331i.txt", "w", stdout);
    srand(time(NULL));

    int T = 100;
    cout << T << endl << endl;
    while(T--) {
        int n = rand() % LIM;
        cout << n << endl;
        int a,b,c,d, x,y;
        a = b = 0;
        double tang = 0;
        for(int i=0; i<n; ) {
            x = a + rand() % LIM;
            y = b + rand() % LIM;

//            cout << "CHECK " << x << ' ' << y << endl; getchar();

//            if(atan2(y-b,x-a) <= theta) continue;

            double temp = 1.0*(y-b)/(x-a);

            if( y == b || x == a || temp <= tang || fabs(temp-tang) > 1 ) continue;

            tang = 1.0*(y-b)/(x-a);
            a = x; b = y;
//            theta = atan2(y-b,x-a);

            cout << a << ' ' << b << endl;
            //getchar();
            i++;
        }
        cout << endl;
    }
}
