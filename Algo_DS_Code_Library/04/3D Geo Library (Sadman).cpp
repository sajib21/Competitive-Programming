/*
    C++ library for 3D geometry

*/

#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define pi acos(-1.0)
#define ll long long


int cmp(double x)
{
    if(fabs(x) < EPS)
        return 0;
    return x < 0 ? -1 : 1;
}

struct point /// CLR
{
    double x, y, z;
    point()
    {
        x = y = 0;
    }
    point(double _x, double _y, double _z)
    {
        x = _x, y = _y, z = _z;
    }
    point operator-(const point &a) const
    {
        return point(x - a.x, y - a.y, z - a.z);
    }
    point operator+(const point &a) const
    {
        return point(x + a.x, y + a.y, z + a.z);
    }
    point operator*(double a) const
    {
        return point(x * a, y * a, z * a);
    }
    point operator*(point b) const
    {
        return point(y * b.z - b.y * z, b.x * z - x * b.z, x * b.y - y * b.x);
    }
    point operator/(double a) const
    {
        return point(x / a, y / a, z / a);
    }
    double val()
    {
        return sqrt(x * x + y * y + z * z);
    }
    void scan()
    {
        scanf("%lf %lf %lf", &x, &y, &z);
    }
    void print()
    {
        printf("(%.4f, %.4f, %.4f)", x, y, z);
    }
//    bool operator<(const point &a)const{
//        vector<ll> X = {round(x), round(y), round(z)};
//        vector<ll> Y = {round(a.x), round(a.y), round(a.z)};
//        return X < Y;
//    }
};

double sq(point p) {return p.x*p.x + p.y*p.y + p.z*p.z;}
double abs(point p) {return sqrt(sq(p));}

double dot(point a, point b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
double det(point p,point q)
{
    return q.x * p.y - q.y * p.x;
}

point cross(point a, point b)
{
    return point(a.y * b.z - b.y * a.z, b.x * a.z - a.x * b.z, a.x * b.y - a.y * b.x);
}
double xmult(point a, point b, point c)
{
    return det(b-a,c - a);
}

double sqLen(point a)
{
    return dot(a,a);
}
double len(point a)
{
    return sqrtl(sqLen(a));
}
double dist(point a, point b)
{
    return len(a - b);
}

inline double heron (double x, double y, double z)
{
    double s = 0.5 * (x + y + z);
    return sqrtl(s * (s - x) * (s - y) * (s - z));
}
inline double getArea(point a, point b, point c)
{
    return fabs(cross(a-b, c-b).val()) / 2.0;
}

struct plane /// CLR
{
    point n;
    double d;
    plane(){}

    /// From normal _n and offset _d
    plane(point _n,double _d)
    {
        n = _n;
        d = _d;
    }
    /// From normal _n and point _p
    plane(point _n,point _p)
    {
        n = _n;
        d = dot(_n,_p);
    }
    /// From three non-collinear points P,Q,R
    plane(point p,point q,point r)
    {
        point D = cross((q-p),(r-p));
        n = D;
        d = dot(D,p);
    }
    /// side(P) is positive if P is on the side of plane pointed by n, and negative for the other side.
    int side(point p)
    {
        return dot(n,p)-d;
    }
    /// returns the distance from point to plane ( this is not "distance from point to face" )
    double dist(point p)
    {
        return abs(side(p))/n.val();
    }
    /// translates the plane where point t resides
    plane translate(point t)
    {
        return plane(n,d+(dot(n,t)));
    }
    /// translates the plane to the direction of normal n at "dist" distance
    plane shiftUp(double dist)
    {
        return plane(n,d+dist*(n.val()));
    }
    point proj(point p)
    {
        return p - n*side(p)/(n.val());
    }
    point refl(point p)
    {
        return p - n*2*side(p)/(n.val());
    }
};

struct line3d /// CLR
{
    point d,o;
    line3d(){}
    line3d(point p,point q)
    {
        d = q-p;
        o = p;
    }
    line3d(plane p1,plane p2)
    {
        d = p1.n*p2.n;
        o = (p2.n*p1.d - p1.n*p2.d)*d/sq(d);
    }

    ///we can sort points according to their position along a line l
    bool cmpProj(point p,point q) {return (dot(d,p))<(dot(d,q));}
    point proj(point p) {
        if (sq(d) < EPS) return o;
        double along = dot(d,p-o)/dot(d,d);
        if (along < 0) along = 0;
        if (along > 1) along = 1;
        return d*along + o;
    }
    double dist(point p)
    {
        point r = proj(p);
        return (r-p).val();
    }


    point refl(point p) {return proj(p)*2-p;}
    ///line-plane intersection
    point inter(plane p) {
        assert(dot(d,p.n) != 0.0 && "line and plane are parallel");
        return o - d*p.side(o)/(dot(d,p.n));
    }
};

struct tri
{
    point a, b, c;
    tri(){}
    tri( point _a,point _b,point _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};


struct face
{
    int n;
    vector<point>pt;
    face()
    {
        n = 3;
        pt.reserve(n);
    }
    face(int _n)
    {
        n = _n;
        pt.reserve(n);
    }
    face(tri tr)
    {
        n = 3;
        pt.reserve(n);
        pt[0] = tr.a;
        pt[1] = tr.b;
        pt[2] = tr.c;
    }
    inline double ComputeSignedArea()
    {
        double area = 0;
        for(int i = 0; i+2 < n; i++)
        {
            area += getArea(pt[0],pt[i+1],pt[i+2]);
        }
        return area;
    }

    inline double ComputeArea()
    {
        return fabs(ComputeSignedArea());
    }
    inline int inside_face(point q, int on_edge=1)
    {
        point q2;
        int i = 0, cnt;
        while(i<n)
        {
            for(cnt = i = 0, q2.x = rand()+10000, q2.y = rand() + 10000,q2.z = rand() + 10000; i<n; i++)
                if( cmp(xmult(q,pt[i],pt[(i+1)%n])) == 0 &&
                    (pt[i].x-q.x)*(pt[(i+1)%n].x-q.x) < EPS &&
                    (pt[i].y-q.y)*(pt[(i+1)%n].y-q.y) < EPS )
                    return on_edge;
                else if( cmp(xmult(q,q2,pt[i]))==0 )
                    break;
                else if( xmult(q,pt[i],q2) * xmult(q,pt[(i+1)%n],q2) < -EPS &&
                        xmult(pt[i],q,pt[(i+1)%n]) * xmult(pt[i],q2,pt[(i+1)%n]) < -EPS )
                    cnt++;
        }
        return cnt&1;
    }
    /// Minimum distance between triangular face and point d
    inline double TrifaceDist (point d)
    {
        point a,b,c;
        a = pt[0];
        b = pt[1];
        c = pt[2];

        point norm = cross(b-a, c-a);
        point ab = b - a;
        point nw = cross(ab, norm);
        assert(nw.val() != 0.0);
        nw = nw / nw.val();
        if(cmp(dot(nw, d-a)) == 1){
            return line3d(a,b).dist(d);
        }

        point bc = c-b;
        nw = cross(bc, norm);
        assert(nw.val() != 0.0);
        nw = nw / nw.val();
        if(cmp(dot(nw, d-b)) == 1)
            return line3d(b,c).dist(d);

        point ca = a-c;
        nw = cross(ca, norm);
        assert(nw.val() != 0.0);
        nw = nw / nw.val();
        if(cmp(dot(nw, d-c)) == 1)
            return line3d(c,a).dist(d);

        double ret = dot(norm, d-a) / norm.val();
        return fabs(ret);
    }
    /// Minimum distance between triangular face and segment "de"
    inline double segtotriFaceDist(point d, point e)
    {
        point ab = e - d;
        double lo = 0, hi = 1;

        for (int it = 0; it < 300; ++it)
        {
            double l = (lo + lo + hi) / 3.0;
            double r = (lo + hi + hi) / 3.0;
            point pL = d + ab * l, pR = d + ab * r;
            double dL = TrifaceDist(pL);
            double dR = TrifaceDist(pR);
            if (dL < dR)
                hi = r;
            else
                lo = l;
        }
        return TrifaceDist(d+ab*lo);
    }

    /// Minimum distance between a face and segment "de" ( Untested )
    inline double segtoFaceDist(point d, point e)
    {
        double res = DBL_MAX;
        face fc(3);
        for(int i=0;i+2<n;i++)
        {
            fc.pt[0] = pt[0];
            fc.pt[1] = pt[i+1];
            fc.pt[2] = pt[i+2];
            res = min(res,fc.segtotriFaceDist(d,e));
        }
        return res;
    }

    /// Minimum distance between two faces
    inline double Face_Face_dist(face &fc2)
    {
        double res = DBL_MAX;
        for(int i=0;i<n;i++)
        {
            int j = (i+1)%n;
            res = min(res,segtoFaceDist(fc2.pt[i],fc2.pt[j]));
            res = min(res,fc2.segtoFaceDist(pt[i],pt[j]));
        }
        return res;
    }
};

vector<tri> convex_hull(vector<point> p,double &area)
{
    vector<tri> ret;
    int n = p.size();
    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
            for(int k = j+1; k<n; k++)
            {
                point norm = cross(p[i]-p[k], p[j]-p[k]);
                vector<point> coplaner;
                int f = 0;
                for(int l = 0; l<n; l++)
                {
                    if(cmp(dot(norm, p[l]-p[k]))==0)
                    {
                        if(face(tri(p[i],p[j],p[k])).inside_face(p[l],1) == false)
                        {
                            f = 1;
                            break;
                        }
                    }
                }
                if(f)
                    continue;
                // code here
                int sig = -2;
                for(int l = 0; l<n; l++)
                {
                    int val = cmp(dot(norm, p[l]-p[k]));
                    if(val != 0)
                    {
                        if(sig==-2)
                            sig = val;
                        else
                        {
                            if(sig != val)
                            {
                                f = 1;
                                break;
                            }
                        }
                    }
                }
                if(!f)
                {
                    area += face(tri(p[i],p[j],p[k])).ComputeArea();
                    ret.push_back({p[i], p[j], p[k]});
                }
            }

    return ret;
}

/// INCOMPLETE
struct sphere
{
    point o;
    double r;
    sphere(){}
    sphere(point _o,double _r)
    {
        o = _o;
        r = _r;
    }
    //int sphereLine()
};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<point> vt;
        for(int i = 0; i<n; i++)
        {
            point a;
            a.scan();
            vt.push_back(a);
        }
        double area = 0.0;
        vector<tri> hull = convex_hull(vt,area);
        vt.clear();
        scanf("%d", &n);
        for(int i = 0; i<n; i++)
        {
            point a;
            a.scan();
            vt.push_back(a);
        }
        vector<tri> hull2 = convex_hull(vt,area);

        double mini = DBL_MAX;
        face fc1(3);
        face fc2(3);

        for(int i = 0; i<(int)hull2.size(); i++)
        {
            fc1.pt[0] = hull2[i].a;
            fc1.pt[1] = hull2[i].b;
            fc1.pt[2] = hull2[i].c;
            for(int j = 0; j<(int)hull.size(); j++)
            {
                fc2.pt[0] = hull[j].a;
                fc2.pt[1] = hull[j].b;
                fc2.pt[2] = hull[j].c;
                mini = min(fc1.Face_Face_dist(fc2), mini);
            }
        }
        printf("%.10f\n", area + mini);
    }
    return 0;
}
