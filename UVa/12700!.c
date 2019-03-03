#include <stdio.h>
int main()
{
    char test,i;

    scanf("%d", &test);
    for(i=1; i<=test; i++)
    {
        char j, b=0, w=0, t=0, a=0;
        int n; //char n diya loop hoy na kn?? :/
        scanf("%d", &n);
        char v[n+1];
        scanf("%s", &v); //getchar/scanf diya miltasilo na kn?? :/
        for(j=0; j<n; j++)
        {
            if(v[j]=='B') b++;
            else if(v[j]=='W') w++;
            else if(v[j]=='T') t++;
            else if(v[j]=='A') a++;
        }
        if(!w && b==n-a && n!=a) printf("Case %d: BANGLAWASH\n", i);
        else if(!b && w==n-a && n!=a) printf("Case %d: WHITEWASH\n", i);
        else if(a==n) printf("Case %d: ABANDONED\n", i);
        else if(b==w) printf("Case %d: DRAW %d %d\n", i, b, t);
        else if(b>w && (w || t)) printf("Case %d: BANGLADESH %d - %d\n", i, b, w);
        else if(w>b && (b || t)) printf("Case %d: WWW %d - %d\n", i, w, b);
    }
    return 0;
}
