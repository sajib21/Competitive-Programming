/// EXTENDED EUCLID ON Ax + By = C
/// OTHER SOLUTIONS : ( x - r*B/g , y + r*A/g ) where g = gcd(A,B) , (x,y) is the general solution from egcd , r is any integer
/// A LOT OF SPECIAL CASES OCCURS

struct euclid {
    ll g, x,y;
    euclid() {}
    euclid(ll gg, ll xx, ll yy) {
        g = gg; x = xx; y = yy;
    }
};

euclid egcd(ll a, ll b) {
    if(b == 0) return euclid(a, 1, 0);
    euclid temp = egcd(b, a%b);
    return euclid(temp.g, temp.y, temp.x - temp.y*(a/b));
}

ll A,B,C, x1,x2, Y1,y2;
ll _A, _B;

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld %lld %lld %lld %lld %lld %lld", &A,&B,&C, &x1,&x2, &Y1,&y2);
        C = -C;
        euclid ans = egcd(A,B);
        if(!ans.g) {
            ll tmp = ((x2-x1+1)*(y2-Y1+1));
            if(!C) printf("Case %d: %lld\n", t, tmp );
            else printf("Case %d: 0\n", t);
        }
        else if(!A) {
            if(C % B == 0 && Y1 <= C/B && C/B <= y2) printf("Case %d: %lld\n", t, x2-x1+1);
            else printf("Case %d: 0\n", t);
        }
        else if(!B) {
            if(C % A == 0 && x1 <= C/A && C/A <= x2) printf("Case %d: %lld\n", t, y2-Y1+1);
            else printf("Case %d: 0\n", t);
        }
        else if(C % ans.g != 0) printf("Case %d: 0\n", t);
        else {
            ll mul = C / ans.g;
            ll x = ans.x*mul , y = ans.y*mul;
            _A = A/ans.g; _B = B/ans.g;

            double xr = -1.0*(x1-x)/_B , xl = -1.0*(x2-x)/_B;
            double yl = 1.0*(Y1-y)/_A , yr = 1.0*(y2-y)/_A;

            if(xl > xr) swap(xl, xr);
            if(yl > yr) swap(yl, yr);

            xl = ceil(xl); xr = floor(xr);
            yl = ceil(yl); yr = floor(yr);

            ll lft = max( xl , yl );
            ll rgt = min( xr , yr );

            if(xl <= yl && yl <= xr) printf("Case %d: %lld\n", t, (ll)(rgt-yl+1) );
            else if(yl <= xl && xl <= yr) printf("Case %d: %lld\n", t, (ll)(rgt-xl+1) );
            else printf("Case %d: 0\n", t);
        }
    }
    return 0;
}
