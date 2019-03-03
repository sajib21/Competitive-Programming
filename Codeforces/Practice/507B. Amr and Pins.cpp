#include<bits/stdc++.h>
#define sqr(x) ( (x) * (x) )

using namespace std;

int main() {
    double r, x,y, X,Y;
    scanf("%lf %lf %lf %lf %lf", &r, &x,&y, &X,&Y);

    double d = sqrt( sqr(x-X) + sqr(y-Y) );

    double t = d / (2*r);

//    cout << "T " << t << endl;

    printf("%d\n", (int)(ceil(t)) );

//    if( floor(t) == t ) printf("%d\n", (int)t  );
//    else printf("%d\n", (int)(floor(t)+2) );

//    main();

}
