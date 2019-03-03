#include<bits/stdc++.h>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

        double A,B,C;
        double l,w;
        scanf("%lf %lf", &l,&w);
        A = 12, B = -4*(l+w), C = l*w;

        double x1 =  ( -B + sqrt(B*B - 4*A*C) ) / (2*A) ; if(x1 <= 0) x1 = 0;
        double x2 =  ( -B - sqrt(B*B - 4*A*C) ) / (2*A) ; if(x2 <= 0) x2 = 0;

//        cout << A << ' ' << B << ' ' << C << endl;
//        cout << x1 << ' ' << x2 << endl;

        printf("Case %d: %.10lf\n", t, max( ( (l-2*x1)*(w-2*x1)*x1) , ( (l-2*x2)*(w-2*x2)*x2) ) );


    }

    return 0;

}
