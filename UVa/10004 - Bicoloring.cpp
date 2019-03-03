#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,e, u,v;

    int color[100000];

    //while(scanf("%d", &n))
    //{
        vector<int>edge[100000];

        if(n==0) return 0;

        scanf("%d", &e);
        for(int i=0; i<e; i++)
        {
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }


        memset(color, 0, sizeof color);

        queue<int>q;
        q.push(0);
        color[0]=1;
        bool flag = true;

        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            int sz = edge[f].size();


            for(int i=0; i<sz; i++)
            {

                if(color[edge[f][i]] == 0)
                {

                    if(color[f]==1) color[edge[f][i]] = 2;
                    else color[edge[f][i]] = 1;
                    q.push(edge[f][i]);
                }
                else
                {
                    if(color[f] == color[edge[f][i]])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }

        if(flag) printf("Yes\n");
        else printf("No\n");
    //}
}
