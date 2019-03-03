///else if cannot be printed this way. correct way : else\nif

#include<bits/stdc++.h>
#define ll long long int
#define vii vector<int>
#define vll vector<ll>
#define pb(x) push_back(x)
#define pp() pop_back()
#define LIM 10000000
#define MOD 1000000007
#define MAX 10000000
#define pi acos(-1)
#define segVar int lft = node << 1 , rgt = (node << 1) + 1 , md = (st+ed) >> 1;
#define pii pair<int,int>
#define EPS 1e-9
#define sqr(x) ((x)*(x))
#define gamma 0.5772156649
#define harm(x) log(x) + gamma + 1.0/(2*x) - 1.0/(12*sqr(x))
#define IND "    "

using namespace std;

int n;

void print() {
    printf("void print( int a");
    for(int i=1; i<n; i++) printf(", int %c", 'a'+i);
    printf(" ) {\n");
    printf("%sprintf( %c%cd", IND, '"', '%') ;
    for(int i=1; i<n; i++) printf(" %cd", '%');
    printf("%cn%c", '\\', '"' );
    for(int i=0; i<n; i++) printf(", %c", 'a'+i);
    printf(" );\n");
    printf("}\n");
}

vii res;
int cnt;
void go(int in) {

    if(in == n) {
        for(int i=0; i<in; i++) printf("%s", IND);
        printf("print( %c", res[0]+'a');
        for(int i=1; i<n; i++) printf(", %c", 'a'+res[i]);
        printf(");\n");
        cnt++;
        return;
    }

    for(int j=res.size()-1; j>=0; j--) {

        for(int i=0; i<in; i++) printf("%s", IND);
        if(j == res.size()-1) printf("if( %c < %c )\n", res[j]+'a' , in+'a' );
        else printf("else\nif( %c < %c )\n", res[j]+'a' , in+'a' );

        res.insert(res.begin()+j+1, in);
        go(in+1);
        res.erase(res.begin()+j+1);
    }
    for(int i=0; i<in; i++) printf("%s", IND);
    printf("else\n");
    res.insert(res.begin(), in);
    go(in+1);
    res.erase(res.begin());
}

void sorted() {
    printf("void sort( int a");
    for(int i=1; i<n; i++) printf(", int %c", 'a'+i);
    printf(" ) {\n");

    res.pb(i);
    go(1);
    res.pp();

    printf("}\n");
}


int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &n);
        printf("Case %d:\n", t);
        print();
        sorted();
    }
    return 0;
}
