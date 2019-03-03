#include<bits/stdc++.h>
#define vii vector<int>
#define pb push_back
#define ll long long int

using namespace std;


struct bigint {

    // representations and structures

    string a; // to store the digits

    int sign; // sign = -1 for negative numbers, sign = 1 otherwise



    // constructors

    bigint() {} // default constructor

    bigint( string b ) { (*this) = b; } // constructor for string



    // some helpful methods

    int size() { // returns number of digits

        return a.size();

    }

    bigint inverseSign() { // changes the sign

        sign *= -1;

        return (*this);

    }

    bigint normalize( int newSign ) { // removes leading 0, fixes sign

        for( int i = a.size() - 1; i > 0 && a[i] == '0'; i-- )

            a.erase(a.begin() + i);

        sign = ( a.size() == 1 && a[0] == '0' ) ? 1 : newSign;

        return (*this);

    }



    // assignment operator

    void operator = ( string b ) { // assigns a string to bigint

        a = b[0] == '-' ? b.substr(1) : b;

        reverse( a.begin(), a.end() );

        this->normalize( b[0] == '-' ? -1 : 1 );

    }



    // conditional operators

    bool operator < ( const bigint &b ) const { // less than operator

        if( sign != b.sign ) return sign < b.sign;

        if( a.size() != b.a.size() )

            return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();

        for( int i = a.size() - 1; i >= 0; i-- ) if( a[i] != b.a[i] )

            return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];

        return false;

    }

    bool operator == ( const bigint &b ) const { // operator for equality

        return a == b.a && sign == b.sign;

    }




    // mathematical operators

    bigint operator + ( bigint b ) { // addition operator overloading

        if( sign != b.sign ) return (*this) - b.inverseSign();

        bigint c;

        for(int i = 0, carry = 0; i<a.size() || i<b.size() || carry; i++ ) {

            carry+=(i<a.size() ? a[i]-48 : 0)+(i<b.a.size() ? b.a[i]-48 : 0);

            c.a += (carry % 10 + 48);

            carry /= 10;

        }

        return c.normalize(sign);

    }

    bigint operator - ( bigint b ) { // subtraction operator overloading

        if( sign != b.sign ) return (*this) + b.inverseSign();

        int s = sign; sign = b.sign = 1;

        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);

        bigint c;

        for( int i = 0, borrow = 0; i < a.size(); i++ ) {

            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);

            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;

            borrow = borrow >= 0 ? 0 : 1;

        }

        return c.normalize(s);

    }

    bigint operator * ( bigint b ) { // multiplication operator overloading

        bigint c("0");

        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 ) {

            while(k--) c = c + b; // ith digit is k, so, we add k times

            b.a.insert(b.a.begin(), '0'); // multiplied by 10

        }

        return c.normalize(sign * b.sign);

    }

    bigint operator / ( bigint b ) { // division operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        bigint c("0"), d;

        for( int j = 0; j < a.size(); j++ ) d.a += "0";

        int dSign = sign * b.sign; b.sign = 1;

        for( int i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b, d.a[i]++;

        }

        return d.normalize(dSign);

    }

    bigint operator % ( bigint b ) { // modulo operator overloading

        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );

        bigint c("0");

        b.sign = 1;

        for( int i = a.size() - 1; i >= 0; i-- ) {

            c.a.insert( c.a.begin(), '0');

            c = c + a.substr( i, 1 );

            while( !( c < b ) ) c = c - b;

        }

        return c.normalize(sign);

    }




    // output method

    void print() {

        if( sign == -1 ) putchar('-');

        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);

    }

};




int cont[20] = {0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1};
vii graph[20];
char seq[15];
bigint dp[1010][20][4];
bool dr[1010][20][4];

int conv(string str) {
    int ans = 0;
    for(int i=0; i<str.size(); i++) {
        ans = ans*10 + (str[i]-'0');
    }
    return ans;
}

void print(bigint ans) {
    string val = ans.a;
    reverse(val.begin(), val.end());
    int sz = val.size();
    int ex = sz % 3; if(!ex) ex = 3;
    for(int i=0; i<ex; i++) printf("%c", val[i]);
    for(int i=ex; i<sz; i+=3) printf(",%c%c%c", val[i],val[i+1],val[i+2]);
    printf("\n");
}

bigint f(int n, int u, int con) {
    if(n == 0) {
        int ret = (con == 1) && (u == 1 || u == 2);
        if(ret) return string("1");
        else return string("0");
    }

    if(dr[n][u][con]) return dp[n][u][con];
    dr[n][u][con] = 1;

    bigint ans = string("0");

    if(con == 2) {
        ans = ans + f(n-1, 1, 1);
        ans = ans + f(n-1, 9, 2);
        ans = ans + f(n-1, 14, 1);
        ans = ans + f(n-1, 15, 1);
        dp[n][u][con] = ans;
        return dp[n][u][con];
    }

    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if(v >= 16) ans = ans + f(n-1, v, 0);
        else if(v >= 14) {
            if(con) ans = ans + f(n-1, v, con);
        }
        else if(v == 8) ans = ans + f(n-1, v, 2);
        else ans = ans + f(n-1, v, con | cont[v]);
    }
    dp[n][u][con] = ans;
    return dp[n][u][con];
}

int main() {
    graph[3].pb(5);
    graph[4].pb(2); graph[4].pb(3); graph[4].pb(8); graph[4].pb(10); graph[4].pb(12);
    graph[5].pb(2); graph[5].pb(3); graph[5].pb(8); graph[5].pb(10); graph[5].pb(12);
    graph[6].pb(7); graph[6].pb(9);
    graph[7].pb(2); graph[7].pb(3); graph[7].pb(8); graph[7].pb(10); graph[7].pb(12);
    graph[8].pb(1); graph[8].pb(9); graph[8].pb(14); graph[8].pb(15);
    graph[9].pb(1); graph[9].pb(7); graph[9].pb(9); graph[9].pb(14); graph[9].pb(15);

    graph[10].pb(11); graph[10].pb(16);
    graph[11].pb(2); graph[11].pb(3); graph[11].pb(8); graph[11].pb(10); graph[11].pb(12);
    graph[12].pb(13); graph[12].pb(17);
    graph[13].pb(2); graph[13].pb(3); graph[13].pb(8); graph[13].pb(10); graph[13].pb(12);

    graph[14].pb(13); graph[14].pb(17);
    graph[15].pb(11); graph[15].pb(16);
    graph[16].pb(7); graph[16].pb(9);
    graph[17].pb(7); graph[17].pb(9);

    int t=1;
    while(scanf("%s", seq)) {
        if(!strcmp("#", seq)) return 0;
        int n = conv(seq);
        printf("%d: ", n);
        bigint ans = (f(n-1, 4, 1)+f(n-1, 6, 0));
        ans = ans + ans;
        print(ans);
    }
    return 0;
}
