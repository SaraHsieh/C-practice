#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int map[MAX][MAX]={{0}}, ans[MAX][MAX]={{0}};
    int i,j,k,n;
    FILE *fin, *fout;
    fin=fopen("3input_3.txt","r");
    fout=fopen("output.txt","w+t");
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fin,"%d",&map[i][j]);
            ans[i][j]=map[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ans[i][k] && ans[k][j])
                    ans[i][j]=1;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(fout,"%d ",ans[i][j]);
        }
        fprintf(fout,"\n");
    }
    return 0;
}
