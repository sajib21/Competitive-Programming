#include<bits/stdc++.h>

using namespace std;

int main() {

    int graph[110][110], aseNaki[110];
    int a,b, s, nodes, t=0;

    while(scanf("%d %d", &a, &b) && a && b) {

        //memset(graph, 0, sizeof(graph));
        //memset(graph, -129, sizeof(graph));
        memset(aseNaki, 0, sizeof(aseNaki));
        for(int i=1; i<110; i++)
            for(int j=1; j<110; j++)
                graph[i][j] = 1000;

        int total = 0; nodes = 2;
        aseNaki[a] = aseNaki[b] = 1;
        graph[a][b] = 1;
        s = max(a,b);

        while(scanf("%d %d", &a,&b) && a && b) {
            graph[a][b] = 1;
            if(!aseNaki[a]) nodes++;
            if(!aseNaki[b]) nodes++;
            aseNaki[a] = aseNaki[b] = 1;

            s = max(s,max(a,b));
        }

        int i,j,k;
        for(int k=1; k<=s; k++) {
            if(!aseNaki[k]) continue;
            for(int i=1; i<=s; i++) {
                if(i==k || !aseNaki[i]) continue;
                for(int j=1; j<=s; j++) {
                    if(i==j || !aseNaki[j]) continue;

                    graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        for(int i=1; i<=s; i++) {
            if(!aseNaki[i]) continue;
            for(int j=1; j<=s; j++) {
                if(i==j || graph[i][j] >= 1000 || !aseNaki[j]) continue;
                total += graph[i][j];
            }
        }

//        cout << 1.0* total / (nodes*(nodes-1))  << endl;
        //cout << total << endl;

        printf("Case %d: average length between pages = %.3lf clicks\n", ++t, 1.0* total / (nodes*(nodes-1)));
    }

    return 0;
}
