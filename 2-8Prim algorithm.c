#include <stdio.h>
#include <stdlib.h>
#define INF 10000
#define MAX 100

int main()
{
    int cost[MAX][MAX]={{0}}, visit[MAX]={0};
    int n, start,i,j,min,count=1,u,v;
    FILE *fin,*fout;
    fin=fopen("8input_2.txt","r");
    fout=fopen("output.txt","w");
    fscanf(fin,"%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            fscanf(fin,"%d",&cost[i][j]);
            if(!cost[i][j])
                cost[i][j]=INF;
        }
    }

    min=INF;
    for(i=1;i<=n;i++)
    { /*找出最低cost的edge，並以數字小的當作起點*/
        for(j=1;j<=n;j++)
        {
            if(cost[i][j]<min && !visit[j])
            {
                min=cost[i][j];
                if(i<=j)
                    start=i;
                else
                    start=j;
            }
        }
    }
    visit[start]=1;

    while(count<n)
    {
        u=0;v=0;
        min=INF;
        for(i=1;i<=n;i++)
        {
            if(!visit[i])
                continue;
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min && !visit[j])
                {
                    u=i;
                    v=j;
                    min=cost[i][j];
                }
            }
        }
        if(u>v)
            fprintf(fout,"%d %d %d %d\n",count++,v,u,cost[u][v]);
        else
            fprintf(fout,"%d %d %d %d\n",count++,u,v,cost[u][v]);
        cost[u][v]=cost[v][u]=INF;
        visit[v]=1;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
