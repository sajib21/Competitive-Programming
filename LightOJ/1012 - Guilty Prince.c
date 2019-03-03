#include <stdio.h>
#include <string.h>

int w,h;
char mat[21][21];

int khoj(int x, int y)
{
    int c=0;
        c++;
        mat[y][x]=0;
        if(x>0 && mat[y][x-1]=='.') c+= khoj(x-1, y);
        if(y>0 && mat[y-1][x]=='.') c+= khoj(x, y-1);
        if(x<w-1 && mat[y][x+1]=='.') c+= khoj(x+1, y);
        if(y<h-1 && mat[y+1][x]=='.') c+= khoj(x, y+1);

    return c;

}

int main()
{
    int t,T, i,j, x,y, ans;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &w, &h);
        getchar();

        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                scanf("%c", &mat[i][j]);
                if(mat[i][j]=='@')
                {
                    x=j; y=i;
                    mat[i][j]='.';
                }
            }
            getchar();
        }
        ans=khoj(x,y);
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
