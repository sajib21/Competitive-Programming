#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned ll
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define mp make_pair
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))

using namespace std;

struct info
{
    ll x,y;
    info() {}
    info(ll xx, ll yy)
    {
        x = xx;
        y = yy;
    }
};

ll n,q;
bool UPRE;
info pnt[110], p;

ll orientation(info p, info q, info r)
{
    ll val = (q.y - p.y) * (r.x - q.x) -
             (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool onSegment(info p, info q, info r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool doIntersect(info p1, info q1, info p2, info q2)
{
    // Find the four orientations needed for general and
    // special cases
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);

//    cout << "ORI " << o1 << ' ' << o2 << ' ' << o3 << ' ' << o4 << endl;

    // General case


    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
    {
        UPRE=true;
        return true;
    }

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
    {
        UPRE=true;
        return true;
    }

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
    {
        UPRE=true;
        return true;
    }

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
    {
        UPRE=true;
        return true;
    }
    if (o1 != o2 && o3 != o4)
        return true;

    return false; // Doesn't fall in any of the above cases
}


bool isInside(info p)
{

    info ex = info(100000,(p.y)+1);

    ll cnt = 0;
    UPRE=false;

    for(int i=0;i<n;i++)
    {

        if(doIntersect(pnt[i], pnt[(i+1)%n], p, ex))
        {
            cnt++;
        }

    }

    return (cnt & 1)||UPRE;
}

int main()
{

//    freopen("1190i.txt", "r", stdin);
//    freopen("1190o.txt", "w",stdout);

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        scanf("%lld", &n);
        for(int i=0; i<n; i++) scanf("%lld%lld", &pnt[i].x, &pnt[i].y);
        scanf("%lld", &q);
        printf("Case %d:\n", t);
        while(q--)
        {
            scanf("%lld%lld", &p.x, &p.y);
            if(isInside(p)) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}
