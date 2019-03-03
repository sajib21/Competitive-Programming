#include<bits/stdc++.h>
#define bug cout << "debug" << endl;

using namespace std;

int main()
{

    //FILE *fp = fopen("out.txt", "w");

    int n, nn=1;
    cin >> n;
    getchar();

    while(n--)
    {
        if(nn != 1) {
            cout << endl;
            //fprintf(fp, "\n");
            nn++;
        }
        else nn++;

        map<string, int> mp, color, level;
        string s, s1,s2;

        while(cin >> s && s.compare("*"))
        {

            mp[s] = 1;
            color[s] = 0;
            level[s] = 0;
        }

        getchar();
        //bug

        string t;
        //nextline(cin, t);
        while( getline(cin, t) && t.compare(""))
        {

//            memset(color, 0, sizeof(color));
//            memset(level, 0, sizeof(level));

            //cout << t << endl;


            int x,y;
            char cs1[30],cs2[30];
            for(x=0; t[x] != ' '; x++)
            {
                cs1[x] = t[x];
            }
            cs1[x] = '\0';
            for(x=x+1, y=0; t[x] != '\0'; x++, y++)
            {
                cs2[y] = t[x];
            }
            cs2[y] = '\0';

            s1 = cs1; s2 = cs2;

            //cin >> s1 >> s2;
            //cout << s1 << " and " << s2 << endl;
            //for(int i=0; i<5; i++) cout << s1[i]; cout << endl;
            //for(int i=0; i<5; i++) cout << s2[i]; cout << endl;


            queue<string> q;
            color[s1] = 1;
            level[s1] = 0;
            q.push(s1);

            while(!q.empty())
            {

                string str = q.front();
                q.pop();

                int sz = str.size();
                for(int i=0; i<sz; i++)
                {
                    for(char c='a'; c<='z'; c++)
                    {
                        string temp = str;
                        temp[i] = c;
                        if(mp[temp] && !color[temp])
                        {
                            color[temp] = 1;
                            level[temp] = level[str] + 1;
                            q.push(temp);
                        }
                    }
                }
            }
            cout << s1 << ' ' << s2 << ' ' <<  level[s2] - level[s1] << endl;
            //fprintf(fp, "%s %s %d\n", s1.c_str(), s2.c_str(), level[s2]-level[s1]);
        }


    }

    //fclose(fp);

    return 0;

}
