#include <bits/stdc++.h>


#define gc getchar
#define pc putchar

using namespace std;

/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
*/

/*
        two functions for policy based data structure. it is

                find_by_order() and order_of_key().

        The first returns an iterator to the k-th largest element (counting from zero),
        the second returns the number of items in a set that are strictly smaller than our item

*/

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
#define For(i,n) for(int i=0;i<n;i++)
#define Rep(i,x,y) for(int i=x;i<=y;i++)
#define eps 1e-8
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt","w", stdout)
#define sz size()
#define dbg(x) cerr << "yo is " << x << endl;
#define dbg2(x,y) printf("yo is %d! and %d!\n",x,y)
#define foreach(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(a) (a) * (a)
#define clr clear()
#define CASE(a) printf("Case %d: ",a)
#define sf(n) scanf("%d", &n)
#define sff(a,b) scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)

//int dx[] = {0,1,0,-1};
//int dy[] = {1,0,-1,0};
//int dx[] = { -1, -1,  0, 1, 1, 1,  0, -1 };
//int dy[] = {  0, -1, -1, -1,  0, 1, 1, 1 };
//int dxK[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
//int dyK[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

//functions

//i64 gcd(i64 a,i64 b){if(!b)return a;return gcd(b,a%b);}

//inline void fastRead(i64 *a){register char c=0;while(c<33)c=gc();*a=0;while(c>33){*a=*a*10+c-'0';c=gc();}}

//inline void fastWrite(int a){char snum[20];int i=0;do{snum[i++]=a%10+48;a=a/10;}while(a!=0);i=i-1;while(i>=0)pc(snum[i--]);pc('\n');}

//i64 bigmod(i64 num,i64 n){if(n==0)return 1;i64 x = bigmod(num,n/2);x = x*x%mod;if(n%2==1)x = x*num % mod;return x;}

//i64 modinverse(i64 num){return bigmod(num,mod-2);}

//void combination(int pos,int last){if(pos==k+1){for(int i=1;i<=k;i++)cout << tem[i];cout << endl;return;}
//for(int i=last+1;i<=n-k+pos;i++){tem[pos] = num[i-1];combination(pos+1,i);}}
//i64 power(i64 value, i64 base){i64 result = 1;For(i,base)result *= value;return result;}
//int Set(int N,int pos){return N = (1<<pos);}
//int reset(int N,int pos){return N &= (~(1<<pos));}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}

//typedef tree< int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > Set;

int dblcmp(double d)
{
    if (fabs(d)<eps)return 0;
    return d>eps?1:-1;
}

struct point
{
    double x,y;

    point() { }
    point(double _x, double _y) { x = _x, y = _y; }

    void input() { scanf("%lf %lf", &x, &y); }
    void output() {cout << x << " " << y << endl;}


    double distance(point p)    {   return hypot(x - p.x, y - p.y);  }
    point sub(point p)          {   return point(x - p.x, y - p.y);  }
    double det(point p)         {   return x * p.y - y * p.x;        }
};

struct line
{
    point a,b;

    line() { }
    line(point _a, point _b) { a = _a, b = _b; }

    double length()     {   return a.distance(b);   }

    int relation(point p)
    {
        int c = dblcmp(p.sub(a).det(b.sub(a)));
        if (c < 0) return 1;
        if (c > 0) return 2;
        return 3;
    }

    point crosspoint(line v)
    {
        double a1 = v.b.sub(v.a).det(a.sub(v.a));
        double a2 = v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x * a2 - b.x * a1) / (a2 - a1), (a.y * a2 - b.y * a1)/(a2 - a1));
    }
};

int main()
{
    int t;
    sf(t);
    Rep(tc,1,t)
    {
        int n;
        sf(n);

        point a;
        double ax;
        scanf("%lf", &ax);
        a = point(ax,0.0);

        vector<point> v;

        point st;
        st.input();
        n--;
        v.pb(st);

        line gg = line(a,st);

        double ans = 0;

        For(i,n)
        {
            point p;
            p.input();

            if(gg.relation(p) != 1)
            {
                v.pb(p);
                continue;
            }
            line kop = line(v[v.sz-1], p);

            point ched = kop.crosspoint(gg);

//            ched.output();
//            p.output();

            line lol = line(ched,p);

            ans += lol.length();

            gg = line(a,p);
            v.pb(p);

        }
        CASE(tc);
        printf("%.6f\n", ans);
    }



    return 0;
}

