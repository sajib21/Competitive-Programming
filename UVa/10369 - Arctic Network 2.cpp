#include <bits/stdc++.h>

using namespace std;

struct edge {
    int first,second;
    double w;

    edge(int uu, int vv, double ww) {
        first=uu; second=vv; w=ww;
    }

    bool operator < (const edge e) const {
        return w < e.w;
    }

};

double dist(pair<int,int>p1, pair<int,int>p2 ) {

    return sqrt( (p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second) );
}

vector<edge>edges, MSTEdges;
int par[505];
FILE *fp = fopen("10369.txt", "w");

int findSet(int a) {

    if(par[a] == a) return a;
    return par[a] = findSet(par[a]);
}

int main() {



    int t;
    cin >> t;
    while(t--) {

        int s,p;
        pair<int,int>coOrdinates[505];
        edges.clear(); MSTEdges.clear();
        cin >> s >> p;


        for(int i=0; i<p; i++) {
            int x,y;
            cin >> x >> y;
            coOrdinates[i] = make_pair(x,y);
        }

        for(int i=0; i<p; i++) {
            for(int j=i+1; j<p; j++) {
                edges.push_back(edge(i,j, dist(coOrdinates[i],coOrdinates[j])));
            }
        }

        sort(edges.begin(), edges.end());

        //int par[505];
        for(int i=0; i<p; i++) par[i] = i;

        int comp = p;
        double ans = 0;
        int sz = edges.size();
        for(int i=0; i<sz && comp > s; i++)
        {
            int u = edges[i].first, v = edges[i].second;
            if(findSet(u) != findSet(v))
            {
                par[par[u]] = par[v];
                comp--;
                ans = edges[i].w;
            }

            //cout << "update : " << ans << endl;
        }

        printf("%.2lf\n", ans);
        fprintf(fp, "%.2lf\n", ans);

    }

    fclose(fp);

    return 0;

}
