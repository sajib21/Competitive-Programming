#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1e6+100;
struct node
{
    int l,r,mark;
    ll sum,tag;
}T[maxn*40];
int root[maxn];
int cnt;//
void pushup(int x)
{
    T[x].sum=T[T[x].l].sum+T[T[x].r].sum;
}
int build(int l,int r)
{
    int root=++cnt;
    T[root].sum=T[root].tag=T[root].mark=0;
    if(l==r)
    {
        scanf("%lld",&T[root].sum);
        T[root].l=T[root].r=0;
        return root;
    }
    int m=(l+r)/2;
    T[root].l=build(l,m);
    T[root].r=build(m+1,r);
    pushup(root);
    return root;
}
void copy(int x,int y)
{
    T[x].sum=T[y].sum;
    T[x].tag=T[y].tag;
    T[x].l=T[y].l;
    T[x].r=T[y].r;
}
void pushdown(int x,int l,int r)
{
    if(T[x].mark)//
    {
        int now=++cnt;
        copy(now,T[x].l);
        T[x].l=now;
        now=++cnt;
        copy(now,T[x].r);
        T[x].r=now;
        T[T[x].l].mark=T[T[x].r].mark=1; //
        T[x].mark=0;
    }
    if(T[x].tag)
    {
        int m=(l+r)/2;
        T[T[x].l].tag+=T[x].tag;
        T[T[x].r].tag+=T[x].tag;
        T[T[x].l].sum+=1ll*T[x].tag*(m-l+1);
        T[T[x].r].sum+=1ll*T[x].tag*(r-m);
        T[x].tag=0;
    }
}
int update(int root,int L,int R,int l,int r,int v)
{
    cout << root << ' ' << L << ' ' << R << ' ' << l << ' '<< r << ' ' << v << endl;
//    getchar();
    int now=++cnt;
    if(l==L&&r==R)
    {
        T[now].l=T[root].l;
        T[now].r=T[root].r;  //
        T[now].sum=T[root].sum+1ll*(r-l+1)*v;
        T[now].tag=T[root].tag+v;
        T[now].mark=l==r?0:1;
        return now;
    }
    int m=(L+R)/2;
    T[now].mark=T[now].sum=T[now].tag=0;//
    pushdown(root,L,R);
    if(r<=m)
    {
        T[now].l=update(T[root].l,L,m,l,r,v);
        T[now].r=T[root].r;
    }
    else if(l>m)
    {
        T[now].l=T[root].l;
        T[now].r=update(T[root].r,m+1,R,l,r,v);
    }
    else
    {
        T[now].l=update(T[root].l,L,m,l,m,v);
        T[now].r=update(T[root].r,m+1,R,m+1,r,v);
    }
    pushup(now);
    cout << now << ' ' << T[now].sum << endl;
    return now;
}

ll query(int root,int L,int R,int l,int r)
{
//    cout << root << ' ' << L << ' ' << R << ' ' << l << ' '<< r << ' ' << T[root].sum << endl;
//    getchar();

    if(L==l&&R==r)
        return T[root].sum;
    pushdown(root,L,R); //
    int m=(L+R)/2;
    if(r<=m) return query(T[root].l,L,m,l,r);
    else if(l>m) return query(T[root].r,m+1,R,l,r);
    else return query(T[root].l,L,m,l,m)+query(T[root].r,m+1,R,m+1,r);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int now=0;
        cnt=0;
        root[now]=build(1,n);
        char op[5];
        while(m--)
        {
            scanf("%s",op);
            int l,r,v;
            if(op[0]=='Q')
            {
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(root[now],1,n,l,r));
            }
            else if(op[0]=='C')
            {
                scanf("%d%d%d",&l,&r,&v);
                now++;
                root[now]=update(root[now-1],1,n,l,r,v);
            }
            else if(op[0]=='H')
            {
                scanf("%d%d%d",&l,&r,&v);
                printf("%lld\n",query(root[v],1,n,l,r));
            }
            else if(op[0]=='B')
                scanf("%d",&v),now=v;
        }
        puts("");
    }
    return 0;
}
