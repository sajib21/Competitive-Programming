int n, val;
char valChar[30], str[60];

string pattern;
int sizePattern;
int prefix[60];

void generatePrefix() {
    prefix[0] = 0;
    for(int i = 0, j = 2; j<sizePattern; j++) {
        while(i > 0 && pattern[i+1] != pattern[j]) i = prefix[i];
        if(pattern[i+1] == pattern[j]) i = i+1;
        prefix[j] = i;
    }
}
///MATEXPO LIBRARY HERE

int main() {
    matrix mat;

    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%lld", &n);
        scanf("%s", valChar); val = strlen(valChar);
        scanf("%s", str);
        pattern = str; pattern = "0" + pattern;
        sizePattern = pattern.size();
        generatePrefix();

        mat = matrix(0);
        matRow = matCol = sizePattern-1;

        for(int c=1; c<sizePattern; c++) {
            int r = c;
            int cnt = 0;
            bool flag[30] = {0};
            while(r > 1) {
                int p = pattern[r] - 'a';
                if(!flag[p]) {
                    mat.mat[r][c-1] = 1;
                    cnt++;
                    flag[p] = true;
                }
                r = prefix[r-1] + 1;
            }

            int p = pattern[r] - 'a';
            if(!flag[p]) {
                mat.mat[r][c-1] = 1;
                cnt++;
                flag[p] = true;
            }

            mat.mat[0][c-1] = val - cnt;
        }

        mat = matBigMod(mat, n);

        ui ans = 0;
        for(int i=0; i<matRow; i++) ans += mat.mat[i][0] ;
        printf("Case %d: %u\n", t, ans);
    }

    return 0;
}
