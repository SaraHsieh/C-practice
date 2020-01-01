#include <stdio.h>
#define MAX 100
FILE *fin, *fout;
int main()
{
    int count[MAX]={0};
    int map[MAX][MAX]={{0}};
    int i,j,n;
    fin=fopen("1input_3.txt","r");
    fout=fopen("output.txt","w");
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fin,"%d",&map[i][j]);
            if(map[i][j])
                count[j]++;
        }
    }

    while(1)
    {
        for(i=0;i<n, count[i]!=0;i++);
        if(i==n)
            break;
        fprintf(fout,"%d ",i+1);
        count[i]=-1;
        for(j=0;j<n;j++)
        {
            if(map[i][j])
                count[j]--;
        }
    }
    return 0;
}
