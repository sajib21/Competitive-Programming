#include<bits/stdc++.h>
#define pii pair<int,int>
#define mpr make_pair
//#define ff first
//#define ss second

using namespace std;

struct info {
    int ff,ss, ans;
    info() {}
    info(int f, int s, int a) {
        ff = f; ss = s; ans = a;
    }
};

int n;
info ara[3030];

bool cmpff(info a, info b) { return a.ff < b.ff; }
bool cmpss(info a, info b) { return a.ss < b.ss; }

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &ara[i].ff);
        ara[i].ss = i;
    }
    n++;

    sort(ara+1, ara+n, cmpff);

//    for(int i=1; i<n; i++) cout << ara[i].ff << ' ' ; cout << endl;

    int x,y,z, p;
    int a=0,b=0,c=0,d=0,e=0;
    int crossa, crossb, crossc;
    for(int i=n-1; i>0; i--) { ///ei porjonto 1st er
        for(int j=i-1; j>0; j--) { ///ei porjonto 2nd er
            for(int k=j-1; k>0; k--) {

                x = n-i; y = (n-x)-j; z = (n-x-y)-k; p = (n-x-y-z);
                if(x <= 2*y && y <= 2*x && y <= 2*z && z <= 2*y && x <= 2*z && z <= 2*x) {
//                    cout << i << ' ' << j << ' ' << k << endl; //getchar();
                    if(ara[i].ff - ara[i-1].ff > a) {
                        a = ara[i].ff - ara[i-1].ff;
                        b = ara[j].ff - ara[j-1].ff;
                        c = ara[k].ff - ara[k-1].ff;
                        crossa = i; crossb = j; crossc = k;
                    }
                    else if(ara[i].ff - ara[i-1].ff == a) {
                        if(ara[j].ff - ara[j-1].ff > b) {
                            b = ara[j].ff - ara[j-1].ff;
                            c = ara[k].ff - ara[k-1].ff;
                            crossa = i; crossb = j; crossc = k;
                        }
                        else if(ara[j].ff - ara[j-1].ff == b) {
                            if(ara[k].ff - ara[k-1].ff > c) {
                                c = ara[k].ff - ara[k-1].ff;
                                crossa = i; crossb = j; crossc = k;
                            }
//                            else if(ara[k].ff - ara[k-1].ff == c)
                        }
                    }
//                    cout << a << ' ' << b << ' ' << c << endl; getchar();
                }
            }
        }
    }
    int id = 1;
    for(int i=n-1; i>0; i--) {
        ara[i].ans = id;
        if(i == crossa || i == crossb || i == crossc) id++;
    }
    sort(ara+1, ara+n, cmpss);

    for(int i=1; i<n; i++) {
        if(i != 1) printf(" ");
        if(ara[i].ans < 4) printf("%d", ara[i].ans);
        else printf("%d", -1);

    }
    printf("\n");

    return 0;
}
