#include<bits/stdc++.h>

using namespace std;

//FILE *fp = fopen("out.txt", "w");

struct node {
    int ver, key;

    node(int v, int k) {
        ver = v; key = k;
    }

    bool operator < (const node &b) const {
        return key < b.key;
    }
    bool operator > (const node &b) const {
        return key > b.key;
    }
};

vector<int>graph[1000010], cost[1000010];
priority_queue<node, vector<node>, greater<node> >pq;
int key[1000010], par[1000010];

int main() {
    int n,m, u,v,c, newEdge, t= 1;
    int preCost, newCost;


    while(scanf("%d", &n) != EOF) {
        preCost = 0; newCost = 0;
        //graph.clear(); cost.clear();
        for(int i=1; i<=n; i++) {
            graph[i].clear(); cost[i].clear();
        }


        for(int i=1; i<n; i++) {
            scanf("%d %d %d", &u,&v,&c);
            preCost += c;
        }
        scanf("%d", &newEdge);
        for(int i=0; i<newEdge; i++) {
            scanf("%d %d %d", &u,&v,&c);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
            //key[u] = key[v] = INT_MAX;
            //par[u] = par[v] = 0;
        }
        scanf("%d", &m);
        for(int i=0; i<m; i++) {
            scanf("%d %d %d", &u,&v,&c);
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(c);
            cost[v].push_back(c);
            //key[u] = key[v] = INT_MAX;
            //par[v] = par[u] = 0;
        }

        for(int i=1; i<=n; i++) {
            key[i] = par[i] = INT_MAX;
        }

        key[1] = 0;

        pq.push(node(1,0));

        while(!pq.empty()) {
            node nd = pq.top();
            pq.pop();

            u = nd.ver;
            int sz = graph[u].size();
            for(int i=0; i<sz; i++) {
                v = graph[u][i];
                if(cost[u][i] < key[v] && v != par[u] && v != u) {
                    key[v] = cost[u][i];
                    par[v] = u;
                    pq.push(node(v, key[v]));
                }
            }
        }

        for(int i=1; i<=n; i++) {
            newCost += key[i];
            //cout << key[i] << "  ";
        }
        //cout << endl;

        if(t != 1) {
            printf("\n");
            //t++;
        }
        printf("%d\n%d\n", preCost, newCost);

//        if(t != 1) {
//            fprintf(fp, "%s", "\n");
//            //t++;
//        }
//        fprintf(fp, "%d\n%d\n", preCost, newCost);

        t++;

    }

//    fclose(fp);

    return 0;
}
