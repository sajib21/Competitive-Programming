#include<bits/stdc++.h>

using namespace std;

string st, ed, a,b,c;
int f;

map<string, int> vis, un;

int BFS() {

    int ans = -1;

    if( un[ st ] ) return ans;

    queue<string>q;
    q.push(st);
    vis[ st ] = 0;

    while(!q.empty()) {

        string u = q.front();
        int lev = vis[u];
        q.pop();

        if(u == ed) return lev;

        string temp;

        temp = u; temp[0] -= 1; if(temp[0] < 'a') temp[0] = 'z';
        if( !vis[ temp ] && !un[ temp ] ) {
            vis[ temp ] = lev+1;
            if(temp == ed) return vis[temp];
            q.push(temp);
        }
        temp = u; temp[0] += 1; if(temp[0] > 'z') temp[0] = 'a';
        if( !vis[ temp ] && !un[ temp ] ) {
            vis[ temp ] = lev+1;
            if(temp == ed) return vis[temp];
            q.push(temp);
        }
        temp = u; temp[1] -= 1; if(temp[1] < 'a') temp[1] = 'z';
        if( !vis[ temp ] && !un[ temp ] ) {
            vis[ temp ] = lev+1;
            if(temp == ed) return vis[temp];
            q.push(temp);
        }
        temp = u; temp[1] += 1; if(temp[1] > 'z') temp[1] = 'a';
        if( !vis[ temp ] && !un[ temp ] ){
            vis[ temp ] = lev+1;
            if(temp == ed) return vis[temp];
            q.push(temp);
        }
        temp = u; temp[2] -= 1; if(temp[2] < 'a') temp[2] = 'z';
        if( !vis[ temp ] && !un[ temp ] ) {
            vis[ temp ] = lev+1;
            if(temp == ed) return vis[temp];
            q.push(temp);
        }
        temp = u; temp[2] += 1; if(temp[2] > 'z') temp[2] = 'a';
        if( !vis[ temp ] && !un[ temp ] ) {
            vis[ temp ] = lev+1;
            if(temp == ed) return vis[temp];
            q.push(temp);
        }

    }
    return ans;

}

int main() {

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {

//        memeset(vis, -1, sizeof(vis));
//        memset(un, 0, sizeof(un));

        cin >> st >> ed;

        vis.clear(); un.clear();

        scanf("%d", &f);
        for(int i=0; i<f; i++) {
            cin >> a >> b >> c;
            int as = a.size(), bs = b.size(), cs = c.size();
            for(int p=0; p<as; p++) {
                for(int q=0; q<bs; q++) {
                    for(int r=0; r<cs; r++) {
                        string temp; temp += a[p]; temp += b[q]; temp += c[r];
                        un[ temp ] = 1;
                    }
                }
            }
        }
        //if(un[st] = 1 || un[ed] == 1) printf("Case %d: %d\n", t, -1);
        //else
            printf("Case %d: %d\n", t, BFS());
    }
    return 0;
}
