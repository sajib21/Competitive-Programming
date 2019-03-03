
/// we are storing divisors less than sqrt(n) for every n
/// time complexity for 10^6 is roughly 10^7
/// Memory complexity for 10^6 is roughly 160 MB
/// For 10^7 its ~10^8 and ~800 MB
/// not tested in any problem

#define mxn 10000067

vi dd[mxn];

void sieve() {
    int tot = 0;
    for(int i = 1; i*i < mxn; i++)
        for(int j = i*i; j < mxn; j += i) {
            tot++;
            dd[j].push_back(i);
        }

    cout << tot << endl;
}


vi get_divisors(int n) {
    vi v;
    For(i,dd[n].sz) {
        int d = dd[n][i];
        v.pb(d);
        if(d==n/d)
            continue;
        v.pb(n/d);
    }

    For(i,v.sz)
    cout << v[i] << " ";
    cout << endl;

    return v;
}

int main() {
    sieve();
    int n;

    while(cin >> n)
        get_divisors(n);

    return 0;
}


