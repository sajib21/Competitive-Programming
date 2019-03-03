#include <bits/stdc++.h>
#define im 200000
using namespace std;

struct node
{

    int vertex, cost;

    node(int ver, int cst) {
        vertex = ver;
        cost = cst;
    }


};

    bool operator > (node a, node b) {
        return a.cost > b.cost;
    }
    bool operator < (node a, node b) {
        return a.cost < b.cost;
    }

map<string, int> indx;
vector<int>graph[220], cost[220];
int cnt = 0, source, dest;
int maxWeight, tempWeight;
int key[220], par[220];

int main()
{
    int t = 1;

    int n,r, limit;
    int u,v;
    string ct1,ct2;

    while(scanf("%d %d", &n, &r) && n && r)
    {
        cnt = 0; indx.clear();
        for(int i=0; i<=n; i++) {
            graph[i].clear(); cost[i].clear();
        }

        for(int i=0 ; i<r; i++)
        {
            cin >> ct1 >> ct2 >> limit;

            if(!indx[ct1])
            {
                u = indx[ct1] = ++cnt;
            }
            if(!indx[ct2])
            {
                v = indx[ct2] = ++cnt;
            }

            u = indx[ct1];
            v = indx[ct2];
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(limit);
            cost[v].push_back(limit);

            key[u] = key[v] = 0;
            par[u] = u; par[v] = v;

        }

        cin >> ct1 >> ct2;
        source = indx[ct1];
        dest = indx[ct2];


        priority_queue<node>pq;

        key[source] = im;
        pq.push(node(source, key[source]));

        maxWeight = im;

        while(!pq.empty()) {
            node nd = pq.top();
            pq.pop();

            u = nd.vertex;

            //cout << nd.cost << endl;


            if(key[u] < maxWeight) maxWeight = nd.cost;

            for(int i=0; i<graph[u].size(); i++) {
                v = graph[u][i];

                if(cost[u][i] > key[v]) {
                    key[v] = cost[u][i];
                    pq.push(node(v, key[v]));
                }

            }
            if(u == dest) break;
        }

        //for(int i=0; i<indx.size(); i++) cout << key[  ]

//        while(par[dest] != dest) {
//            if(key[dest] < maxWeight) maxWeight = key[dest];
//            dest = par[dest];
//            cout << maxWeight << endl;
//        }

        //if(t!=1) cout << "\n";

        cout << "Scenario #" << t++ << endl;
        cout << maxWeight << " tons" << endl;
        cout << endl;
    }

    return 0;
}
