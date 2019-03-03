#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007
#define maxn 100005
#define DBG pf("Hi\n")
#define INF 2000000000
#define infd 1000000000.0 ;
#define i64 long long int
#define eps (1e-8)
#define ff first
#define ss second
#define ln 17
#define sq 318

using namespace std ;

vector <int> sub[maxn], big, elements[maxn] ;
int type[maxn], idx[maxn], n, k ;
int common[sq][maxn] ;
i64 ara[maxn] ;
i64 sum[maxn], update[maxn] ;

void updateBigPacket(i64 id, i64 updateVal) {
//   pf("big packet updating: %lld\n",id) ;
    int i ;
    for(i=0 ; i<k ; i++) {
        //     pf("%lld\n",sum[i]) ;
        sum[i] += updateVal*common[ idx[id] ][ big[i] ] ;
        //   pf("%d %lld\n",i,sum[i]) ;
    }
    update[ idx[id] ] += updateVal ;
}
void updateSmallPacket(i64 id, i64 updateVal) {
    i64 i ;
    for(i=0 ; i<sub[id].size() ; i++) ara[ sub[id][i] ] += updateVal ;
    for(i=0 ; i<k ; i++) sum[i] += common[ i ][ id ]*updateVal ;
}

i64 querySmallPacket(i64 id) {
    //  cout<<"call to querySmallPacket"<<endl ;
    //  pf("id: %lld size of subset: %lld\n",id,(i64)sub[id].size()) ;
    i64 ret = 0,i ;
    for( i=0 ; i<sub[id].size() ; i++  ) {
        ret += ara[ sub[id][i] ] ;
        //     pf("%d %lld\n",sub[id][i],ara[sub[id][i] ] ) ;
    }
    //  pf("ret %lld\n",ret) ;
    //  pf("end of this query\n") ;
    for(i=0 ; i<k ; i++ ) ret += update[i]*common[ i ][id] ;

    return ret ;
}
i64 queryBigPacket(i64 id) {
    //  cout<<"call to queryBigPacket"<<endl ;
    return sum[ idx[id] ] ;
}

int main() {
    int i, j, l, m, s, q, sz ;

    char str[5] ;

    cin>>n>>s>>q ;

    for(i=0 ; i<n ; i++) sf("%lld",&ara[i]) ;

    for(i=0,k=0 ; i<s ; i++) {
        sf("%d",&sz) ;

        if( sz >= sq ) {
            type[i] = 1 ;
            big.pb(i) ;
            idx[i] = k ;
        }

        for(j=0 ; j<sz ; j++) {
            sf("%d",&m) ;
            m-- ;
            sub[i].pb(m) ;
            if(type[i]) sum[k] += ara[m] ;
            elements[m].pb(i) ;
        }
        if(type[i]) k++ ;
    }

    /*   for(i=0 ; i<n ; i++)
       {
           pf("index no %d:",i) ;
           for(j=0 ; j<elements[i].size() ; j++) pf(" %d",elements[i][j]) ;
           pf("\n") ;
       }
    */
    //  for(i=0 ; i<s; i++) pf("subset size %d %d\n",i,(int)sub[i].size()) ;

    for( i=0 ; i<n ; i++ ) {
        for(j=0; j<elements[i].size() ; j++) {
            if( type[ elements[i][j] ] ) {
                for(l=0 ; l<elements[i].size() ; l++) common[ idx[elements[i][j]] ][elements[i][l]]++ ;
            }
        }
    }
    /*   for(i=0 ; i<k ; i++)
       {
           for(j=0 ; j<s ; j++) pf("big packet's id: %d small packets id: %d common elements: %d\n",i,j,common[i][j]) ;
       }
    */
    //  for(i=0 ; i<k ; i++) pf("sum of big packets %d: %lld\n",i,sum[i]) ;

    for( i=0 ; i<q ; i++ ) {
        sf("%s",str) ;
        if( str[0] == '+' ) {
            i64 id, val ;
            sf("%lld %lld",&id,&val) ;
            id-- ;
            if( type[id] ) updateBigPacket( id, val ) ;
            else updateSmallPacket( id, val ) ;
        } else {

            i64 id ;
            sf("%lld",&id) ;
            id-- ;
            if( type[id] ) pf("%lld\n",queryBigPacket(id)) ;
            else pf("%lld\n",querySmallPacket(id)) ;
        }

    }

    return 0 ;
}
/*
5 3 100
5 -5 5 1 -4
2 1 2
4 2 1 4 5
2 2 5
? 2
+ 3 4
? 1
+ 2 1
? 2
*/
