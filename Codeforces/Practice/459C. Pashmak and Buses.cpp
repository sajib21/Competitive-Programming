#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int n,k,d;
//vector<int> sol;

void genPer()
{

    ll ii = 1;
    for(int i=1; i<=d; i++)
    {
        //int ii = 1;
        for(int j=1, b = 1; j<=n; )
        {

            if(b > k) b = 1;
            //int ii = 1 << (i-1);
            printf("%d", b); j++;
            for(int c=1; c<ii && j<=n; c++)
            {
                printf(" %d", b);
//                printf("%d", b);
                j++;
            }
            if(j <= n) printf(" ");
            //j--;
            b++;
            //ii *= 2;
        }
        printf("\n");
        ii *= k;
    }
}

int main()
{

    scanf("%d %d %d", &n,&k,&d);
    //double tmp = log(n)/log(k);
    //cout << d << ' ' << tmp << endl;


    if( log(n)/log(k) - (double) d > 1e-9)
    {
        printf("-1\n");
    }
    else
    {
        genPer();
    }

    return 0;
}
