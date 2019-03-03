int n,q, ara[LIM+10];
int BIT[LIM+10];

void update(int indx, int val) {
    while(indx <= n) {
        BIT[indx] += val;
        indx += (indx & -indx);
    }
}
int query(int indx) {
    int sum = 0;
    while(indx > 0) {
        sum += BIT[indx];
        indx -= (indx & -indx);
    }
    return sum;
}
int singleQuery(int idx){
    int sum = tree[idx];
    int z = idx - (idx & -idx);
    idx--;
    while (idx != z){
        sum -= tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int rangeQuery(int idx, int idy) {
    int sum = 0;
    while(idx != idy) {
        if(idx < idy) {
            sum += tree[idy];
            idy -= (idy & -idy);
        }
        else {
            sum -= tree[idx];
            idx -= (idx & -idx);
        }
    }
    return sum;
}

int main() {

    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &ara[i]);
    for(int i=1; i<=n; i++) update(i, ara[i]);

    scanf("%d", &q);
    while(q--) {
        int a,b;
        scanf("%d %d", &a,&b);
        cout << query(b) - query(a-1) << endl;
    }
    return 0;
}
