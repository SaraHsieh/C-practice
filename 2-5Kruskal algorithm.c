#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 10000

int size, map[MAX][MAX],parent[MAX]={0};

int find_root(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int check(int a, int b)
{
    if(a==b)
        return 0;
    parent[b]=a;
    return 1;
}

int main()
{
    int i,j;
    int a,b,u,v,min,count=1;
    FILE *fin,*fout;
    fin=fopen("5input_2.txt","r");
    fout=fopen("output.txt","w");
    fscanf(fin,"%d",&size);
    for(i=1;i<=size;i++)
    {
        for(j=1;j<=size;j++)
        {
            fscanf(fin,"%d",&map[i][j]);
            if(map[i][j]==0)
                map[i][j]=INF;
        }
    }

    while(count<size)
    {
        min=INF;
        a=0,b=0,u=0,v=0;
        for(i=1;i<=size;i++)
        {
            for(j=1;j<=size;j++)
            {
                if(map[i][j]<min)
                {
                    a=u=i;
                    b=v=j;
                    min=map[i][j];
                }
            }
        }
        u=find_root(u);
        v=find_root(v);
        if(check(u,v))
        {
            fprintf(fout,"%d %d %d\n",a,b, map[a][b]);
            count++;
        }
        map[a][b]=map[b][a]=INF;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
