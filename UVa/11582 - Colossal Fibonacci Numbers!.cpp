#include<bits/stdc++.h>
//#include<stdio.h>
#define ll unsigned long long int

using namespace std;

#define MAX 1000

int f(int a, ll b, int mod) {
//    cout << a << ' ' << b << ' ' << mod << endl; getchar();
    if(!b) return 1;
    if(b&1) return (a * f(a,b-1, mod))%mod;
    int temp = f(a, b/2, mod);
    return (temp*temp) % mod;
}

ll a,b;
int n;

int main() {
//    clrscr();
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%llu %llu %d", &a,&b,&n);
        if(n == 1) {
            printf("0\n");
            continue;
        }
        int x=0,y=1,z;
        int i;
        for(i=2; ; i++) {
            z = (x+y) % n;
            x = y;
            y = z;

//            cout << i << " : " << x << ' ' << y << endl; //getchar();

            if(x == 0 && y == 1) break;
        }
        i--;
//        i++;

//        cout << a << ' ' << b << endl;
        int N = f(a%i, b, i);
//        cout << i << ' ' << N << endl;
        x = 0, y = 1;

        if(N == 0 || N == 1) {
            if(N == 0) printf("0\n");
            else printf("1\n");
            continue;
        }

        for(i=1; i<N; i++) {
            z = (x+y) % n;
            x = y;
            y = z;
        }
        printf("%d\n", y);
//        cout << x << ' ' << z << endl;
    }
    return 0;
}
