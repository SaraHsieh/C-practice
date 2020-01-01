#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 10000

int cost[MAX][MAX],start,end,n,distance[MAX],visit[MAX]={0},previous[MAX]={0};
FILE *fin,*fout;
int choose()
{
    int i,u=-1,min=INF;
    for(i=1;i<=n;i++)
    {
        if(!visit[i] && distance[i]<min)
        {
            min=distance[i];
            u=i;
        }
    }
    return u;
}
void printpath(int a)
{
    if(previous[a]==-1)
        return;
    printpath(previous[a]);
    fprintf(fout,"%d ",a);
    return;
}

int main()
{
    int i,j;
    int count=1,next;

    fin=fopen("7input_1.txt","r");
    fout=fopen("output.txt","w");
    fscanf(fin,"%d ",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            fscanf(fin,"%d",&cost[i][j]);
            if(!cost[i][j])
                cost[i][j]=INF;
        }
    }
    fscanf(fin,"%d %d",&start,&end);

    for(i=1;i<=n;i++)
    {  /*distance用來存start到各點的距離*/
        distance[i]=cost[start][i];
    }
    visit[start]=1;
    previous[start]=-1;
    next=choose(); /*先選出cost最小的邊當起點*/
    previous[next]=start;
    //visit[next]=1;
    //distance[start]=0;


    while(count<n)
    {
        next=choose();  /*choose中會選cost最小的，前面的程式中已經設定起點的cost為0，因此第一個選的為起點*/
        if(next<0)  /*choose中最一開始的回傳值u=-1*/
            break;
        visit[next]=1;

        for(i=1;i<=n;i++)
        {
            if(!visit[i])
            {
                if(distance[next]+cost[next][i]<distance[i])
                {
                    distance[i]=distance[next]+cost[next][i];
                    previous[i]=next;
                }
            }
        }
        count++;
    }
    if(distance[end]==INF)
        fprintf(fout,"-1\n");
    else
    {
        fprintf(fout,"%d ",start);
        printpath(end);

    }
    fclose(fin);
    fclose(fout);
    return 0;
}
