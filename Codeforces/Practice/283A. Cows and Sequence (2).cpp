#include<bits/stdc++.h>
#define LIM 5000006
#define ll long long int

using namespace std;

int n=1,k, prop[LIM], val[LIM];
ll sum;

int main() {
    scanf("%d", &k);
    while(k--) {
        int c,x,y;
        scanf("%d", &c);
        if(c == 1) {
            scanf("%d %d", &x,&y); x--;
            sum += y*(x+1);
            prop[x] += y;
        }
        else if(c == 2) {
            scanf("%d", &x);
            sum += x;
            val[n++] = x;
        }
        else {
            n--;
            sum -= val[n];
            sum -= prop[n];
            if(n) prop[n-1] += prop[n];
            prop[n] = 0;
        }
        printf("%.10lf\n", 1.0*sum/n);
    }
    return 0;
}
