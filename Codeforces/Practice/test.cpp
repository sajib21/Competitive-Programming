#include<bits/stdc++.h>
#define maxi 2147483647
using namespace std;
int cost[10005][10005];
bool vis[10005][10005];
char mat[10005][10005];
int r,c;
int main()
{
    while(1)
    {
        scanf("%d %d",&r,&c);
        if(r==0 && c==0)
        {
            break;
        }
        int i,j;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                scanf(" %c",&mat[i][j]);
            }
        }
        cout << "RPITN" << endl;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                printf("%c", mat[i][j]);
            }
            printf("\n");
        }

        int l,ans=0;
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                l=1;
                if(mat[i][j]=='*')
                {
                    l=0;
                    for(int k=i-1; k<=i+1; k++)
                    {
                        for(int u=j-1; u<=j+1; u++)
                        {
                            if((mat[k][u]=='*'))
                            {
                                l++;
                            }
                        }
                    }
                    if(l==1)
                    {
                        ans++;
                    }
                }

            }


        }
        printf("%d\n",ans);

    }
    return 0;
}
