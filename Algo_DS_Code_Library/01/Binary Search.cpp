/// NEVER UNDERESTIMATE THE POWER OF CONDITIONS IN BINARY SEARCH
bool BS(int val) {
    int lo = 0, hi = rs; /// HI MUST BE GREATER THAN LAST INDEX OTHERWISE LAST INDEX WILL NEVER BE CHECKED
    while(lo < hi) {
        int md = (lo+hi) >> 1; ///DONT ADD ANYTHING HERE

        if(val+vrc[md] == w) return true;
        if(val+vrc[md] < w) lo = md;
        else hi = md;

        if(lo + 1 == hi) { ///MUST BE LIKE THIS
            if(flag) break;
            flag = true;
        }
    }
}

///BINARY_SEARCH
int bs_upper_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x >= a[mid]) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int bs_lower_bound(int a[], int n, int x) {
    int l = 0;
    int h = n; // Not n - 1
    while (l < h) {
        int mid = (l + h) / 2;
        if (x <= a[mid]) {
            h = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
