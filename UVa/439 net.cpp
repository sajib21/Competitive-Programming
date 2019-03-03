#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010



string s1,s2;
int cost[10][10];
bool vis[10][10];
int Dx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int Dy[]= {-1,-2,-2,-1, 1,2, 2, 1};

void bfs(int sx,int sy,int dx,int dy)
{
    int x, y;
    queue< pair<int,int> >Q;
    pair<int, int>pii;
    pii.first=sx;
    pii.second=sy;
    Q.push(pii);
    cost[sx][sy]=0;
    CLR(vis);
    vis[sx][sy]=true;

    while(!Q.empty())
    {
        pii=Q.front();
        Q.pop();
        if(pii.first==dx && pii.second==dy)
        {
            cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<cost[pii.first][pii.second]<<" knight moves.\n";
            return ;
        }
        for(int i=0; i<8; i++)
        {
            x=pii.first + Dx[i];
            y=pii.second + Dy[i];
            if(  x>=1 && x<=8 && y>=1 && y<=8 && !vis[x][y])  //boundary check
            {
                vis[x][y]=true;
                cost[x][y]=cost[pii.first][pii.second]+1;
                Q.push(make_pair(x, y));
            }
        }
    }
}

int main()
{
    int dx,dy,sx,sy;
    while(cin>>s1>>s2)
    {
        sx=s1[0]-96;
        sy=s1[1]-'0';

        dx=s2[0]-96;
        dy=s2[1]-'0';
        bfs(sx,sy,dx,dy);
    }
    return 0;
}
