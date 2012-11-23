#include <iostream>

using namespace std;

int v[25][4];
int n;
int s[25][4];
int snum[25];
int c=0;

int p[5][5][4] = {0};

int solve(int num)
{
    if(num == n*n)
        return 1;

    for(int i=0; i<c; i++)
    {
        if(snum[i] > 0)
        {
            int x=num/n;
            int y=num%n;

            if(x==0 && y==0)
            {
                p[x][y][0] = s[i][0];
                p[x][y][1] = s[i][1];
                p[x][y][2] = s[i][2];
                p[x][y][3] = s[i][3];

                snum[i]--;

                if(solve(num+1) == 1)
                    return 1;

                snum[i]++;
            }
            else
            {
                if(x==0)
                {
                    if(s[i][3] == p[x][y-1][1])
                    {
                        p[x][y][0] = s[i][0];
                        p[x][y][1] = s[i][1];
                        p[x][y][2] = s[i][2];
                        p[x][y][3] = s[i][3];
                        
                        snum[i]--;

                        if(solve(num+1) == 1)
                            return 1;

                        snum[i]++;
                    }
                }

                if(y==0)
                {
                    if(s[i][0] == p[x-1][y][2])
                    {
                        p[x][y][0] = s[i][0];
                        p[x][y][1] = s[i][1];
                        p[x][y][2] = s[i][2];
                        p[x][y][3] = s[i][3];
                        
                        snum[i]--;

                        if(solve(num+1) == 1)
                            return 1;

                        snum[i]++;
                    }
                }

                if(x!=0 && y!=0)
                {
                    if(s[i][0] == p[x-1][y][2] && s[i][3] == p[x][y-1][1])
                    {
                        p[x][y][0] = s[i][0];
                        p[x][y][1] = s[i][1];
                        p[x][y][2] = s[i][2];
                        p[x][y][3] = s[i][3];
                        
                        snum[i]--;

                        if(solve(num+1) == 1)
                            return 1;

                        snum[i]++;
                    }
                }
            }
        }
    }

    return 0;
}

int main()
{
    int game = 1;
    while(cin>>n && n)
    {
        c = 0;
    
        for(int i=0; i<n*n; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>v[i][j];
            }

            int temp = 1;
            for(int k=0; k<c; k++)
            {
                if(v[i][0] == s[k][0] && v[i][1] == s[k][1] &&
                    v[i][2] == s[k][2] && v[i][3] == s[k][3])
                {
                    temp = 0;
                    snum[k]++;
                }
            }

            if(temp == 1)
            {
                s[c][0] = v[i][0];
                s[c][1] = v[i][1];
                s[c][2] = v[i][2];
                s[c][3] = v[i][3];
                snum[c]++;
                c++;

            }
        }
        
        if(game != 1)
            cout<<endl;

        if(solve(0) == 1)
            printf("Game %d: Possible\n", game);
        else
            printf("Game %d: Impossible\n", game);

        game++;

        for(int j=0; j<c; j++)
            snum[j] = 0;
    }
    return 1;
}