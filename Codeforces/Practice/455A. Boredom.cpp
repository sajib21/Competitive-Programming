#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int n, sz, ans = 0, mz=0, mf = 10000000;
vector<int>ara;
int cntAra[100005];
ll dp[100010];

ll getMax(ll u) {

    //cout << u << endl;
    if(u > mz) {
        //cout << "FINALLY PAISI " << ex << endl;
        //ans = max(ans, ex);
        return 0;;
    }


    if(dp[u]) return dp[u];

    ll temp = 0;
    for( ; !cntAra[u] && u<=mz; u++);
    //for(int i=u; i<sz; i++) {
        if( cntAra[ u ] > 0) {
            //int x = cntAra[ u+1 ], y = cntAra[ u-1 ]; // z = cntAra[ ara[i] ];
            //cntAra[ u+1 ] = 0; cntAra[ u-1 ] = 0;//  cntAra[ ara[i] ] = 0;
            //cout << ara[u] << " hoya 1st call" << endl;
            temp = max(temp, u*cntAra[ u ] + getMax(u+2));
            //cntAra[ u+1 ] = x; cntAra[ u-1 ] = y; // cntAra[ ara[i] ] = z;
            //cout << ara[u] << " hoya 1st call theke paisi " << temp << endl;
            //break;
        }
    //}



       // cout << ara[u] << " hoya 2nd " << endl;
        temp = max(temp, getMax(u+1));
        //cout << ara[u] << " hoya 2nd thk paisi " << temp << endl;
    //}

    return dp[u] = temp;
}

int main() {

    scanf("%d", &n);
    int t;
    for(int i=0; i<n; i++) {
        //int t;
        scanf("%d", &t);//cout  << "bug" << endl;
        //if(!cntAra[t]) ara.push_back(t);
        cntAra[ t ]++;
        mz = max(mz, t);
        mf = min(mf, t);
    }


    //sort(ara.begin(), ara.end());
    //sz = ara.size();

//    for(int i=0; i<sz; i++) {
//        //if(i%10 == 0) cout << endl;
//        printf("%d   %d\n", ara[i], cntAra[ ara[i] ]);
//    }
    cout << getMax(mf) << endl;
    //cout << ans << endl;

    return 0;
}
