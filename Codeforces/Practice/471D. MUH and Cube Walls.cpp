#include<bits/stdc++.h>
#define LIM 200005
#define vii vector<int>
#define pb push_back

using namespace std;

char temp[LIM];
vii text, pattern;
int sizeText, sizePattern;
int prefix[LIM];
vector<int>results;

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}

void matchingCheck() {
    int i=1, j=1, k=1;
    while(i < sizeText) {
        while(j < sizePattern && text[i] == pattern[j]) i++ , j++;
        if(j == sizePattern) results.push_back(k);
        if(prefix[j-1] > 0) k = i - prefix[j-1];
        else {
            if(i == k) i++;
            k = i;
        }
        if(j > 1) j = prefix[j-1] + 1;
    }
}

int n,m, a[LIM], b[LIM];

int main() {
    pattern.pb(0);
    text.pb(0);

    scanf("%d %d", &n,&m);

    if(m == 1) {
        cout << n << endl;
        return 0;
    }

    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);

    int mn = INT_MAX;
    for(int i=0; i<n-1; i++) a[i] -= a[i+1], mn = min(mn, a[i]);
    for(int i=0; i<m-1; i++) b[i] -= b[i+1], mn = min(mn, b[i]);

//    for(int i=0; i<n-1; i++) cout << a[i] << ' ' ; cout << endl;
//    for(int i=0; i<m-1; i++) cout << b[i] << ' ' ; cout << endl;

    mn--;
//    cout << mn << endl;

    for(int i=0; i<m-1; i++) pattern.pb(b[i]-mn); // temp[i] = b[i] - mn;
//    temp[m-1] = 0;
//    pattern = temp;

    for(int i=0; i<n-1; i++) text.pb(a[i]-mn); // temp[i] = a[i] - mn;
//    temp[n-1] = 0;
//    text = temp;

//    pattern = "0" + pattern;
    sizePattern = pattern.size();
//    text = "0" + text;
    sizeText = text.size();

//    for(int i=1; i<sizePattern; i++) cout << (int)pattern[i] << ' ' ; cout << endl;
//    for(int i=1; i<sizeText; i++) cout << (int)text[i] << ' ' ; cout << endl;

    generatePrefix();
    matchingCheck();

    cout << results.size() << endl;
}
