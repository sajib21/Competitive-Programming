#include<bits/stdc++.h>
#define LIM 1000006
#define pb push_back
#define     segVar          int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;


using namespace std;

int n, a[LIM], m, x,y,k;
vector<int>segTree[4*LIM];

void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

void init(int node, int st, int ed) {
    if(st == ed) {
        segTree[node].pb(a[st]);
        return;
    }
    segVar;
    init(lft, st,md); init(rgt, md+1,ed);
    int i=0, j=0;
    while(i<segTree[lft].size() && j<segTree[rgt].size()) {
        if(segTree[lft][i] < segTree[rgt][j]) segTree[node].pb(segTree[lft][i++]);
        else segTree[node].pb(segTree[rgt][j++]);
    }
    while(i<segTree[lft].size()) segTree[node].pb(segTree[lft][i++]);
    while(j<segTree[rgt].size()) segTree[node].pb(segTree[rgt][j++]);
}

int query(int node, int st, int ed, int l, int r, int x) {
    if(ed < l || st > r) return 0;
    if(st >= l && ed <= r) {
        return upper_bound(segTree[node].begin(), segTree[node].end(), x) - segTree[node].begin();
    }
    segVar;
    return query(lft, st,md, l,r, x) + query(rgt, md+1, ed, l,r, x);
}

int main() {
    fastscan(n);
    fastscan(m);
//    scanf("%d %d", &n, &m);
//    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
    for(int i=1; i<=n; i++) {
        int num;
        fastscan(num);
        a[i] = num;
    }
    init(1, 1,n);

    sort(a+1, a+n+1);
//    for(int i=1; i<=n; i++) cout << a[i] << ' ' ; cout << endl;

    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &x,&y,&k);
        int lo = 1, hi = n, md;
        while(lo < hi) {
            md = (lo+hi) / 2;
            int temp = query(1, 1,n, x,y, a[md]);
//            cout << "BS " << lo << ' ' << hi << ' ' << md << ' ' << a[md] << ' ' << temp << endl; getchar();
            if(temp >= k) hi = md;
            else lo = md+1;
        }
        printf("%d\n", a[hi]);
    }
}
