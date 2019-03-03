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

        int sz = edges.size();
        for(int i=0; i<sz; i++) {

            edge e = edges[i];

            if(findSet(e.first) != findSet(e.second)) {
                par[ par[e.first] ] = par[e.second];
                MSTEdges.push_back(e);
            }
        }

        int sat[505] = {0};

        cout << "prothome " << MSTEdges[ MSTEdges.size() - 1 ].w << endl;

        int MSTSize = MSTEdges.size()-1;
        while(s) {
            bool con1 = false, con2=false;
            edge e = MSTEdges[MSTSize--];

            cout << "top edge er weight hoilo : " << e.w << endl;

            if(!sat[e.first] && s>0) {
                sat[e.first] = 1;
                s--;
                con1 = true;
                cout << e.first << " 1 e dhukse " << e.second << endl;
            }
            else if(sat[e.first]) {
                con1 = true;
                cout << e.first << " 2 e dhukse " << e.second << endl;

            }

            if(!sat[e.second] && s>0) {
                sat[e.second] = 1;
                s--;
                con2 = true;
                cout << e.first << " 3 e dhukse " << e.second << endl;

            }
            else if(sat[e.second]) {
                con2 = true;
                cout << e.first << " 4 e dhukse " << e.second << endl;
            }

            if(con1 && con2) MSTEdges.pop_back();cout << e.w << endl;
        }

        while(!MSTEdges.empty()) {
            edge e = MSTEdges[MSTEdges.size()-1];
            if(sat[ e.first ] && sat[ e.second ]) {
                MSTEdges.pop_back();
            }
            else {
                break;
            }
        }

        //cout << setprecision(2) <<  MSTEdges[MSTSize].w << endl;
        if(MSTEdges.empty()) printf("0.00\n");
        else printf("%.2lf\n", MSTEdges[MSTEdges.size() - 1].w);
    }

    return 0;

}
