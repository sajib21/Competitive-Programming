#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define gc getchar
    #define pc putchar
#else
    #define gc getchar_unlocked
    #define pc putchar_unlocked
#endif

using namespace std;

#define vi vector<int>
#define si set<int>
#define vs vector<string>
#define pii pair<int,int>
#define vpi vector<pii>
#define pri priority_queue<int>
#define rev_pri priority_queue<int,vector<int>,greater<int> >
#define mpi map<int,int>
#define i64 long long int
#define endl '\n'
#define pi acos(-1)
#define all(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf INT_MAX/2
#define infll LLONG_MAX/3
#define For(i,n) for(int i=0;i<n;i++)
#define Fre(i,a,b) for(int i = a; i < b; i++)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pfn(n) printf("%d\n", n)
#define pfs(n) printf("%d ", n)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define READ freopen("in.txt", "r", stdin)
#define WRITE freopen("out.txt", "w", stdout)
#define sz size()
#define dbg(i) printf("yo %d\n", i)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)

//int dx[] = {0,1,0,-1,1,1,-1,-1};
//int dy[] = {1,0,-1,0,1,-1,-1,1};


//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

//inline void fastRead(int *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}

//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x=bigmod(num,n/2);x=x*x%mod;if(n%2==1)x=x*num%mod;return x;}

//i64 modinverse(i64 num){return bigmod(num,mod-2)%mod;}

//i64 po(i64 a,i64 b){i64 ans=1;while(b--)ans *= a;return ans;}

//i64 ncr(i64 n,i64 r){if(n==r)return 1;if(r==1)return n;if(dp[n][r]!=-1)return dp[n][r];return dp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);}


// bit manipulations

//bool checkbit(int mask,int bit){return mask & (1<<bit);}

//int setbit(int mask,int bit){ return mask  (1<<bit) ; }

//int clearbit(int mask,int bit){return mask & ~(1<<bit);}

//int togglebit(int mask,int bit){return mask ^ (1<<bit);}



int degree[55], indegree[55] , outdegree[55];
vi v[55],vt[55],vun[55];
int n,tot;
bool vis[55];
vi top;

bool taken[55];

void dfs(int gg)
{
        vis[gg] = 1;
        tot++;
        For(i,vun[gg].sz)
                if(!vis[vun[gg][i]])
                        dfs(vun[gg][i]);
}




// 1 if undirected graph is euler path or circuit possible
bool eulerUn()
{
        tot = 0;

        Fre(i,1,n+1)
                if(degree[i]%2==0)
                        tot++;
        if(tot==n-2 || tot==n)
                return 1;
        return 0;
}


void topo(int s)
{
        if(!taken[s])
        {
                taken[s] = 1;
                For(i,v[s].sz)
                        if(!taken[v[s][i]])
                                topo(v[s][i]);
                top.pb(s);
        }
}

void dfs2(int s)
{
        vis[s] = 1;
        For(i,vt[s].sz)
                if(!vis[vt[s][i]])
                        dfs2(vt[s][i]);
}




bool iscircuit()
{
        top.clr;
        mem(taken,0);
        Fre(i,1,n+1)
                if(!taken[i] )
                        topo(i);
        int scc = 0;

        reverse(all(top));
        mem(vis,0);
        For(i,top.sz)
        {

                int u = top[i];
                if(!vis[u])
                {
                        scc++;
                        if(scc>1)
                                break;
                        dfs2(u);

                }
                if(scc>1)
                        break;
        }
        if(scc==1)
                return 1;
        return 0;
}




bool eulerDi()
{
        int sou = 0 , des = 0 , soman = 0 ;

        Fre(i,1,n+1)
        {

                if(indegree[i]==outdegree[i])
                        soman++;
                else if(indegree[i]==outdegree[i]-1)
                        des++;
                else if(indegree[i]-1==outdegree[i])
                        sou++;
        }

        bool ok = 0;
      //  cout << soman << " " << nodes << endl;
        if(soman==n)
                ok = iscircuit();
        else if(sou==1 && des==1 && soman==n-2)
                ok = 1;


        return ok;
}


void f()
{
        // checking if connected
        mem(vis,0);
        tot = 0;
        dfs(1);
        if(tot!=n)
        {
                puts("WAKE UP EARLIER");
                return;
        }

        int f1 = eulerUn();
//        cout << f1 << endl;
//
        int f2 = eulerDi();
//        cout << f2 << endl;


        if(f2)
                puts("YES");
        else if(f1)
                puts("TRAFFIC STOPPING NEEDED");
        else
                puts("WAKE UP EARLIER");

}



int main()
{

        int t,m,a,b;
        sf(t);
        while(t--)
        {

                mem(degree,0);
                mem(indegree,0);
                mem(outdegree,0);
                mem(v,NULL);
                mem(vt,NULL);
                mem(vun,NULL);

                sff(n,m);


                while(m--)
                {
                        sff(a,b);


                        vun[a].pb(b);
                        vun[b].pb(a);

                        v[a].pb(b);
                        vt[b].pb(a);

                        degree[a]++;
                        degree[b]++;

                        indegree[b]++;
                        outdegree[a]++;
                }

                f();
        }













        return 0;
}


