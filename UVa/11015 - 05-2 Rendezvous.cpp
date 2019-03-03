#include<bits/stdc++.h>
#define im 100000
using namespace std;

int main() {
    int n,m, u,v, c, t=0;
    string names[25];
    int graph[25][25];

    while(scanf("%d %d", &n,&m) && n) {

        int total = 0,ti, minm = im;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j) graph[i][j] = graph[j][i] = 0;
                else graph[i][j] = graph[j][i] = im; ///REMI
            }
        }

        for(int i=1; i<=n; i++) {
            cin >> names[i];
        }
        for(int i=0; i<m; i++) {
            cin >> u >> v >> c;
            graph[u][v] = graph[v][u] = c;
        }

        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++) {
                //if(i==k) continue;
                for(int j=1; j<=n; j++) {
                    //if(i==j) continue;
                    graph[i][j] = min( graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        //total = 0;
        for(int i=1; i<=n; i++) {
            total = 0;
            for(int j=1; j<=n; j++) {
                //if(i==j) continue;
                if(graph[i][j] >= im) {
                    total = im;
                    break;
                }
                total += graph[i][j];
            }
            if(total < minm) {
                ti = i;
                minm = total;
            }
        }

//        for(int i=1; i<=n; i++) {
//            for(int j=1; j<=n; j++) {
//                cout << graph[i][j];
//            }
//            cout << endl;
//        }

        //Case #1 : timotius
        printf("Case #%d : ", ++t);
        cout << names[ti] << endl;
    }

    return 0;
}
