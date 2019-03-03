/// EXTENDED EUCLID ON Ax + By = C
/// OTHER SOLUTIONS : ( x - r*B/g , y + r*A/g ) where g = gcd(A,B) , (x,y) is the general solution from egcd , r is any integer
/// A LOT OF SPECIAL CASES OCCURS

struct euclid {
    int g, x,y;
    euclid() {}
    euclid(int gg, int xx, int yy) {
        g = gg; x = xx; y = yy;
    }
};
euclid egcd(int a, int b) {
    if(b == 0) return euclid(a, 1, 0);
    euclid temp = egcd(b, a%b);
    return euclid(temp.g, temp.y, temp.x - temp.y*(a/b));
}
int main() {
    euclid ans = egcd(-10, -8);
    cout << ans.g << ' ' << ans.x << ' ' << ans.y << endl;
    return 0;
}
