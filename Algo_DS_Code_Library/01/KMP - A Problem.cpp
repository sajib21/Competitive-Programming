/// PROBLEM : GIVEN A PATTERN, PROBABILITY OF EACH CHARACTER BEING CHOSED AND THE SIZE OF TEXT,
/// YOU HAVE TO DETERMINE THE PROBABILITY OF CHOOSING SUCH A TEXT SO THAT THE PATTERN DOESN'T OCCUR IN THE TEXT.

string text, pattern;
int n, sizeText, sizePattern;
int prefix[110];
vector<int>results;
double prob[27];

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

bool vis[LIM+100][LIM+100];
double dp[LIM+100][LIM+100];

double f(int in, int k) { /// in: current index of text, k: current index of pattern ;
        /// function is looking for the probability of the pattern being PRESENT in text
    if(k == sizePattern) return 1;
    if(in == sizeText) return 0;
    if(vis[in][k] != 0) return dp[in][k];

    double ans = 0;
    bool taken[27] = {0};
    int j = k;
    while(prefix[j-1]) {
        int p = pattern[j] - 'a' ;

        if(prob[p] != 0 && !taken[p]) {
            taken[p] = 1;
            ans += prob[p]*f(in+1, j+1);
        }
        j = prefix[j-1] + 1;
    }

    int p = pattern[j] - 'a' ; /// here, j is 1
    if(prob[p] != 0 && !taken[p]) {
        taken[p] = 1;
        ans += prob[p]*f(in+1, j+1);
    }
    j = prefix[j-1] + 1;

    for(int p=0; p<26; p++) if(prob[p] != 0 && !taken[p]) {
        ans += prob[p]*f(in+1,1);
    }
    vis[in][k] = 1;
    return dp[in][k] = ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        for(int i=0; i<26; i++) prob[i] = 0;
        memset(vis, 0, sizeof vis);
        memset(dp, 0, sizeof dp);
        cin >> pattern;
        scanf("%d %d", &n, &sizeText); ///n: number of valid char
        for(int i=0; i<n; i++) {
            char c; double p;
            getchar();
            scanf("%c %lf", &c, &p); ///valid char, probb of choosing
            prob[c-'a'] = p;
        }

        pattern = "0" + pattern;
        sizePattern = pattern.size();
        sizeText++;
        generatePrefix();

        double ans = f(1,1);
        printf("%lf\n", 1-ans);
    }

    return 0;
}
